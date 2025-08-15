// post.hpp
namespace POST
{

// Message for request 2
// Expected: Receive success message with status 201 Created
const char* message2 = 
"POST /modify.txt HTTP/1.1\n"
"Host: myopenserver.com\n"
"Content-Length: 1023\n"
"Content-Type: application/txt\n"
"\n"
"{'name':'new_name','color':'red'}";



// Message for request 7
// Expected: Receive success message with status 201 Created
const char* message7 = 
"POST /modify.txt HTTP/1.1\n"
"Host: mysecretserver.com\n"
"Authorization: correct_access_code\n"
"Content-Length: 1023\n"
"Content-Type: application/txt\n"
"\n"
"{'name':'new_name','color':'green'}";

};