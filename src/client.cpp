// client.cpp
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include "get.hpp"
#include "post.hpp"

using namespace std;

void handleRequest(const char* message, size_t message_len, char* buffer, int buffer_size, int clientSocket)
{
    send(clientSocket, message, message_len, 0);
    recv(clientSocket, buffer, buffer_size, 0);
    cout << "Message from server:\n" << buffer << endl;
    return;
}

int main()
{
    // Initializing the client socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    char buffer[1024] = {0};

    const char* messages[] = {GET::message1, POST::message2, GET::message3, GET::message4, 
                                GET::message5, GET::message6, POST::message7, GET::message8, 
                                GET::message9, GET::message10};
    int messages_length = sizeof(messages) / sizeof(messages[0]);

    // Handle requests
    for (int i = 0; i < messages_length; i++){
        handleRequest(messages[i], strlen(messages[i]), buffer, sizeof(buffer), clientSocket);
    }
    


    // Closing server
    const char* closing_msg = "Close";
    send(clientSocket, closing_msg, strlen(closing_msg), 0);

    close(clientSocket);

    return 0;
}
