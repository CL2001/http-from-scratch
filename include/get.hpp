// get.hpp
namespace GET
{
// Message for request 1
// Expected: Receive content with status 200 OK
const char* message1 = 
"GET / HTTP/1.1\n"
"Host: myopenserver.com\n";

// Message for request 3
// Expected: Receive modified content with status 200 OK
const char* message3 = 
"GET / HTTP/1.1\n"
"Host: myopenserver.com\n";

// Message for request 4
// Expected: Receive error with status 401 Unauthorized
const char* message4 = 
"GET / HTTP/1.1\n"
"Host: mysecretserver.com\n";

// Message for request 5
// Expected: Receive error with status 401 Unauthorized
const char* message5 = 
"GET /protected HTTP/1.1\n"
"Host: mysecretserver.com\n"
"Authorization: incorrect_access_code\n";

// Message for request 6
// Expected: Receive content with status 200 OK
const char* message6 = 
"GET /protected HTTP/1.1\n"
"Host: mysecretserver.com\n"
"Authorization: correct_access_code\n";

// Message for request 8
// Expected: Receive modified content with status 200 OK
const char* message8 = 
"GET /protected HTTP/1.1\n"
"Host: mysecretserver.com\n"
"Authorization: correct_access_code\n";


// Message for request 9
// Expected: Receive moved error (301 Moved Permanently)
const char* message9 = 
"GET / HTTP/1.1\n"
"Host: myopenserver_old.com\n";

// Message for request 10
// Expected: Receive error (404 Not Found)
const char* message10 = 
"GET / HTTP/1.1\n"
"Host: unkown.com\n";

};




