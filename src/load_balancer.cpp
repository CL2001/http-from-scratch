#include "load_balancer.hpp"

std::string extractGetPost(std::string message)
{
    return " ";
}


std::string extractServer(std::string message)
{
    return " ";
}

std::string extractBody(std::string message)
{
    return " ";
}


std::string LoadBalancer::balanceLoad(std::string message)
{
    std::string server = extractServer(message);
    if (server == "Closing")
    {
        return "Closing";
    }


    std::string body = "Hi I am the server";
    return Responses::r200(body);
}
