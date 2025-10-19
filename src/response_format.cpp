#include "response_format.hpp"

std::string Response::r200(std::string msg)
{
    std::string body = "OK 200. " + msg + "\r\n";
    return  "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: " + std::to_string(body.size()) + "\r\n"
            "\r\n" +
            body;
}

std::string Response::r201(std::string msg)
{
    std::string body = "Created 201. " + msg + "\r\n";
    return  "HTTP/1.1 201 Created\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: " + std::to_string(body.size()) + "\r\n"
            "\r\n" +
            body;
}

std::string Response::r301(std::string new_location)
{
    std::string body = "Warning 301. Server moved to: " + new_location + "\r\n";

    return "HTTP/1.1 301 Moved Permanently\r\n"
           "Location: " + new_location + "\r\n"
           "Content-Length: " + std::to_string(body.size()) + "\r\n"
           "\r\n" +
           body;
}


std::string Response::r401()
{
    return  "HTTP/1.1 401 Unauthorized\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 26\r\n"
            "\r\n"
            "Error 401: Access denied"
            "\r\n";
}

std::string Response::r404()
{
    return  "HTTP/1.1 404 Not Found\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 22\r\n"
            "\r\n"
            "Error 404: Not found"
            "\r\n";
}



std::string Response::r418()
{
    return  "HTTP/1.1 418 I'm a teapot\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 25\r\n"
            "\r\n"
            "Error 418: I'm a teapot\r\n";
}