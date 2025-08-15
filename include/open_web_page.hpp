#ifndef OPEN_WEB_PAGE_HPP
#define OPEN_WEB_PAGE_HPP
#include "web_page.hpp"
#include <string>




class OpenWebPage: public WebPage {
private:


public:
OpenWebPage();
std::string treatRequest(std::string) override;

};

#endif