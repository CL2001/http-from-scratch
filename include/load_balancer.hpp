#pragma once
#include <string>
#include "response_format.hpp"

namespace LoadBalancer
{
enum class RequestType {
    Get,
    Post
};

struct Header {
    RequestType request_type{RequestType::Get};
    std::string server{"Error"};
};

std::string balanceLoad(std::string);
};
