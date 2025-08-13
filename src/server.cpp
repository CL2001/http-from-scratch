// server.cpp
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "handle_response.hpp"


void receiveLoop(int &clientSocket)
{
    // Set 1 kB buffer char buffer[1024] = {0};
    char buffer[1024] = {0};
    while (true)
    {
        // Receiving data from client
        ssize_t message_size = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);

        // Detects error
        if (message_size <= 0) //ssize_t is set to -1 when an error occurs
        {
            std::cout << "Error, message is -1" << std::endl;
            return;
        }

        // Set last byte to end string
        buffer[message_size] = '\0';

        // Display message
        std::cout << "Message from client:\n" << buffer << std::endl;

        if (strcmp(buffer, "Close") == false)
        {
            std::cout << "Closing server" << std::endl;
            return;
        }

        // Sending response back to client
        std::string response = handle_response(buffer, static_cast<int>(message_size));
        const char* c_response = response.c_str();
        send(clientSocket, c_response, strlen(c_response), 0);
    }
}


int main()
{
    // Initializing the server socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    listen(serverSocket, 5);
    int clientSocket = accept(serverSocket, nullptr, nullptr);

    receiveLoop(clientSocket);

    // Close sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
