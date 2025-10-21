// load_balancer.hpp
#pragma once
#include <string>
#include "response_format.hpp"
#include "server.hpp"


namespace LoadBalancer
{
std::string balanceLoad(std::string);
};
