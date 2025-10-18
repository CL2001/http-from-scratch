#include "response_format.hpp"

std::string Responses::r200(std::string body)
{
    body += "\n";
    return "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/plain\r\n"
    "Content-Length: " + std::to_string(body.size()) + "\r\n"
    "\r\n" +
    body;
}
