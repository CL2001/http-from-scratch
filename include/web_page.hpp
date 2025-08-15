#ifndef WEB_PAGE_HPP
#define WEB_PAGE_HPP
#include <string>




class WebPage {
private:
std::string content;
std::string detectMessageType(std::string);
void modifyContent(std::string);
std::string extractPostContent(std::string);


public:
virtual std::string treatRequest(std::string);

};

#endif