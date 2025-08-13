#include <iostream>
#include <string>
#include "handle_response.hpp"

std::string handle_response(const char* message, int message_length)
{
    std::string msg = "";
    if (message_length >= 3 && message[0] == 'G' && message[1] == 'E' && message[2] == 'T')
    {
        msg = "GET received";
    }
    else if (message_length >= 4 && message[0] == 'P' && 
            message[1] == 'O' && message[2] == 'S' && message[3] == 'T')
    {
        msg = "POST received";
    }
    else
    {
        msg = "error";
    }
    return msg;
}