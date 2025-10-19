#include "load_balancer.hpp"


#include <iostream>


LoadBalancer::Header extractHeader(std::string first_line)
{
    LoadBalancer::Header header;
    size_t first_space = first_line.find(' ');
    if (first_space == std::string::npos) {return header;}
    std::string request_type_string = first_line.substr(0, first_space);
    if (request_type_string == "GET")
        header.request_type = LoadBalancer::RequestType::Get;
    else if (request_type_string == "POST")
        header.request_type = LoadBalancer::RequestType::Post;
    else
        return header;

    std::string remainder = first_line.substr(first_space + 1);
    size_t second_space = remainder.find(' ');
    if (second_space == std::string::npos) {return header;}
    header.server = remainder.substr(0, second_space);
    
    return header;
}

std::string extractBody(std::string message)
{

    return " ";
}


std::string LoadBalancer::balanceLoad(std::string message)
{
    size_t first_new_line = message.find('\n');
    std::string first_line = (first_new_line != std::string::npos) ? message.substr(0, first_new_line) : message;

    LoadBalancer::Header header = extractHeader(first_line);
    std::cout << "Header: " << header.server << std::endl; 
    if (header.server == "/closing" || header.server == "Error")
    {
        return Responses::r418();
    }


    std::string body = "Hi I am the server";
    return Responses::r200(body);
}
