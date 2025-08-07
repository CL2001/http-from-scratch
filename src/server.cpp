// server.cpp
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

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

    // Receiving data from client
    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Message from client: " << buffer << endl;

    // Sending response back to client
    const char* response = "Hello from server!";
    send(clientSocket, response, strlen(response), 0);

    // Close sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
