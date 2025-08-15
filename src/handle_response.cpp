#include <iostream>
#include <string>
#include "handle_response.hpp"



std::string detectServer(std::string message)
{
    int index = 0;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == '\n')
        {
            index = i;
            break;
        }
    }
    std::string server_string;
    for (int i = index; i < message.length(); i++)
    {
        if (message[i] == '\n')
        {
            index = i;
        }
        server_string.push_back(message[i]);
    }
    server_string.erase(0, 7);
    return server_string;
}

std::string handleResponse(std::string message)
{
    std::string request_type = "To do in server";
    std::string server_address = detectServer(message);

    std::cout << "request type: " << request_type << "  server_address: " << server_address << std::endl;

    return "temp";
}