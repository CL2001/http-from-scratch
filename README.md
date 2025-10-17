# HTTP From Scratch

This project aims at recreating the HTTP/1 protocol from scratch in c++
We have a server and a client binary interacting and communicating using the http protocol by requesting and sending information


A tcp style connection at the transport layer is assumed since the communication between two binaries is extremely reliable and the focus of this project is http not tcp.
The connection will be made over sockets so the focus remains on http



## Start the server
To use, install make sure a c++ compiler and cmake are installed

Start the server
```bash
make
```


## Run these commands in a seperate terminal

Basic server response
```bash
curl localhost:8080
```

Returns an html file in output.html
```bash
curl -o output.html localhost:8080/public-html
```

Modify a page and retrieve it
```bash
curl -X POST -d "message=I love this!" localhost:8080/modify
```
```bash
curl localhost:8080/modify
```

Access private hidden ressources
```bash
curl -u username:password localhost:8080/private
```


All c++ code is found in the src folder and header files are found in the include folder

Research: https://developer.mozilla.org/en-US/docs/Web/HTTP/Guides/Evolution_of_HTTP