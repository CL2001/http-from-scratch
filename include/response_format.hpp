// response_format.hpp
#pragma once
#include <string>


namespace Response
{
std::string r200(std::string);
std::string r201(std::string);
std::string r301(std::string);
std::string r401();
std::string r404();
std::string r418();
};

