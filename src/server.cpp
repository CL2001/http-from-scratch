// server.cpp
#include "server.hpp"


std::string Server::normal(Message message)
{
    return Response::r200("hi");
}


std::string Server::pub(Message message)
{
    return Response::r200("hi");
}


std::string Server::modify(Message message)
{
    return Response::r200("hi");
}


std::string Server::displaced(Message message)
{
    return Response::r200("hi");
}


std::string Server::priv(Message message)
{
    return Response::r200("hi");
}


std::string Server::notFound(Message message)
{
    return Response::r404();
}