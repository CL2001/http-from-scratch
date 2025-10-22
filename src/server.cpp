// server.cpp
#include "server.hpp"


std::string Server::normal(Message message)
{
    return Response::r200("Feel free to write a message to one of the following servers:\n"
                          "/public to receive publically available information\n"
                          "/modify to read or post comments posted in real time\n"
                          "/dsiplaced to visualize a responsed of a moved server\n"
                          "/private to display private information. Don't forget your password\n"
                          "/not_found or anything else to see the response of a non existing server\n");
}


std::string Server::pub(Message message)
{
    return Response::r200("This information is publically available");
}

std::string modify_string = "Hi this is the comment board\n";
std::string Server::modify(Message message)
{
    if (message.request_type == RequestType::Post)
    {
        modify_string += message.body + "\n";
        return Response::r201(message.body);
    }
    return Response::r200(modify_string);
}


std::string Server::displaced(Message message)
{
    return Response::r301("new_location.com");
}

#include <iostream>
std::string Server::priv(Message message)
{
    std::string msg_to_find = "Authorization: Basic ";
    size_t auth_pos = message.msg.find(msg_to_find);
    if (auth_pos == std::string::npos)
        return Response::r401();
    std::string rest = message.msg.substr(auth_pos + msg_to_find.length());

    size_t end_auth_pos = rest.find('\r');
    if (end_auth_pos == std::string::npos)
        return Response::r401();
    std::string user_id = rest.substr(0, end_auth_pos);

    if (user_id == "dXNlcm5hbWU6cGFzc3dvcmQ=")
        return Response::r200("This is private data you can only see with your user name and password");
    return Response::r401();
}


std::string Server::notFound()
{
    return Response::r404();
}