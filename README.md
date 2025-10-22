# HTTP From Scratch

This project aims at recreating the HTTP/1.1 and HTTP/2.0 protocol from scratch in C++
We have a create a server on port 8080, or any other port desired using C++ sockets.
Using C++ sockets doesn't make the project entirely from scratch, but since c++ sockets are essentially a wrapper around system calls, I consider the use of C++ sockets as justified. Re-implementing the TCP/IP layer would duplicate kernel functionality and distract from the core goal


## Start the server
To use, install make sure a c++ compiler and cmake are installed

Start the server
```bash
make
```


## Run these commands in a seperate terminal
Add -v for verbose responses.

Basic server response
```bash
curl localhost:8080
```

Returns an html file in output.html (Returns 200)
```bash
curl localhost:8080/public
```

Modify a page and retrieve it (Returns 201 for post command)
```bash
curl localhost:8080/modify
```
```bash
curl -X POST -d "I am modifying!" localhost:8080/modify
```
```bash
curl localhost:8080/modify
```

Displaced server (Returns 301 for post command)
```bash
curl localhost:8080/displaced
```

Access private hidden ressources (Return 401 for error)
```bash
curl -u wrong_username:wrong_password localhost:8080/private
```
```bash
curl -u username:password localhost:8080/private
```

Page not found (Return 404 for error)
```bash
curl localhost:8080/notfound
```

Close server (will return a teapot error as an easter egg)
```bash
curl localhost:8080/closing
```


All c++ code is found in the src folder and header files are found in the include folder

Research: https://developer.mozilla.org/en-US/docs/Web/HTTP/Guides/Evolution_of_HTTP