// load_balancer.cpp
#include "load_balancer.hpp"


Message extractHeader(std::string first_line)
{
    Message header;
    size_t first_space = first_line.find(' ');
    if (first_space == std::string::npos) {return header;}
    std::string request_type_string = first_line.substr(0, first_space);
    if (request_type_string == "GET")
        header.request_type = RequestType::Get;
    else if (request_type_string == "POST")
        header.request_type = RequestType::Post;
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
    size_t pos = message.rfind('\n');
    std::string last_line = (pos == std::string::npos) ? message : message.substr(pos + 1);
    return last_line;
}


std::string LoadBalancer::balanceLoad(std::string msg)
{
    size_t first_new_line = msg.find('\n');
    std::string first_line = (first_new_line != std::string::npos) ? msg.substr(0, first_new_line) : msg;

    Message message = extractHeader(first_line);
    if (message.request_type == RequestType::Post)
    {
        message.body = extractBody(msg);
    }

    // Send request to server
    if (message.server == "/closing" || message.server == "Error")
        return Response::r418();
    else if (message.server == "/")
        return Server::normal(message);
    else if (message.server == "/public")
        return Server::pub(message);
    else if (message.server == "/modify")
        return Server::modify(message);
    else if (message.server == "/displaced")
        return Server::displaced(message);
    else if (message.server == "/private")
        return Server::priv(message);
    else
        return Server::notFound();
}
