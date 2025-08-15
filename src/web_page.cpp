#include "web_page.hpp"



std::string WebPage::detectMessageType(std::string message)
{
    std::string request_type = "";
    if (message.length() >= 3 && message[0] == 'G' && message[1] == 'E' && message[2] == 'T')
    {
        request_type = "get";
    }
    if (message.length() >= 4 && message[0] == 'P' && 
            message[1] == 'O' && message[2] == 'S' && message[3] == 'T')
    {
        request_type = "post";
    }
    return request_type;
};

void WebPage::modifyContent(std::string content)
{
    content = content;
};