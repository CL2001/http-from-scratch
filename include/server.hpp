// server.hpp
#pragma once
#include <string>
#include "response_format.hpp"


enum class RequestType {
    Get,
    Post
};


struct Message {
    RequestType request_type{RequestType::Get};
    std::string server{"Error"};
    std::string body{""};
};


namespace Server
{
std::string normal(Message);
std::string pub(Message);
std::string modify(Message);
std::string displaced(Message);
std::string priv(Message);
std::string notFound();
};
