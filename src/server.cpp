// server.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <csignal>

void handleClient(int connection)
{
    char buffer[4096]; //4 kB

    // Receive request
    ssize_t bytes_received = recv(connection, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received <= 0)
    {
        std::cout << "Client disconnected or error occurred.\n";
        return;
    }

    buffer[bytes_received] = '\0';
    std::cout << "Request from client:\n" << buffer << std::endl;

        // Compose response
    std::string body = "Hi I am the server";
    body += "\n";

    std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Content-Length: " + std::to_string(body.size()) + "\r\n"
        "\r\n" +
        body;

    // Send response
    ssize_t bytes_sent = send(connection, response.c_str(), response.size(), 0);
    if (bytes_sent == -1)
    {
        std::cerr << "Send failed (client may have closed connection)\n";
        return;
    }

}

int main()
{
    signal(SIGPIPE, SIG_IGN);

    int port = 8081;
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        std::cerr << "Failed to create socket. errno: " << errno << std::endl;
        return 1;
    }

    // Allow address reuse (so you can restart quickly)
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        std::cerr << "Bind failed. errno: " << errno << std::endl;
        return 1;
    }

    if (listen(server_socket, 10) < 0)
    {
        std::cerr << "Listen failed. errno: " << errno << std::endl;
        return 1;
    }

    std::cout << "Server listening on port " << port << "...\n";

    int max_requests = 3;
    int i = 0;
    while (i < 3)
    {
        i++;
        sockaddr_in client_addr{};
        socklen_t client_len = sizeof(client_addr);
        int connection = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (connection < 0)
        {
            std::cerr << "Accept failed. errno: " << errno << std::endl;
            continue;
        }

        std::cout << "New connection accepted.\n";
        handleClient(connection);
        close(connection);
    }

    close(server_socket);
    return 0;
}
