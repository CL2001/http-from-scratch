// server.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <csignal>
#include "safe_socket.hpp"
#include "load_balancer.hpp"

bool handleClient(int connection)
{
    bool closing_server = false;
    char buffer[4096]; //4 kB

    // Receive request
    ssize_t bytes_received = recv(connection, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received <= 0)
    {
        std::cout << "Client disconnected or error occurred.\n";
        return true;
    }

    buffer[bytes_received] = '\0';
    std::string message = buffer;
    std::cout << "Request from client:\n" << message << std::endl;


    std::string response = LoadBalancer::balanceLoad(message);
    if (response == "Closing")
    {
        closing_server = true;
    }


    // Send response
    ssize_t bytes_sent = send(connection, response.c_str(), response.size(), 0);
    if (bytes_sent == -1)
    {
        std::cerr << "Send failed (client may have closed connection)\n";
        return true;
    }
    return closing_server;
}

int main()
{
    signal(SIGPIPE, SIG_IGN);

    int port = 8080;
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    SafeSocket safe_server_socket(server_socket);
    if (safe_server_socket.get() == -1)
    {
        std::cerr << "Failed to create socket. errno: " << errno << std::endl;
        return 1;
    }

    // Allow address reuse (so you can restart quickly)
    int opt = 1;
    setsockopt(safe_server_socket.get(), SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(safe_server_socket.get(), (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        std::cerr << "Bind failed. errno: " << errno << std::endl;
        return 1;
    }

    if (listen(safe_server_socket.get(), 10) < 0)
    {
        std::cerr << "Listen failed. errno: " << errno << std::endl;
        return 1;
    }

    std::cout << "Server listening on port " << port << "...\n";

    int max_requests = 3;
    int i = 0;
    bool close_server = false;
    while (i < 3 && !close_server)
    {
        i++;
        sockaddr_in client_addr{};
        socklen_t client_len = sizeof(client_addr);
        int connection = accept(safe_server_socket.get(), (struct sockaddr*)&client_addr, &client_len);
        if (connection < 0)
        {
            std::cerr << "Failed to establish connection. errno: " << errno << std::endl;
            return 1;
        }

        std::cout << "New connection accepted.\n";
        SafeSocket safe_socket(connection);
        close_server = handleClient(connection);
    }

    return 0;
}
