#include "response_format.hpp"

std::string Responses::r200(std::string body)
{
    body += "\r\n";
    return "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: " + std::to_string(body.size()) + "\r\n"
            "\r\n" +
            body;
}


std::string Responses::r418()
{
    return "HTTP/1.1 418 I'm a teapot\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 25\r\n"
            "\r\n"
            "Error 418: I'm a teapot\r\n";
}