# HTTP From Scratch

This project aims at recreating the HTTP/1 protocol from scratch in c++
We have a server and a client binary interacting and communicating using the http protocol by requesting and sending information


A tcp style connection at the transport layer is assumed since the communication between two binaries is extremely reliable and the focus of this project is http not tcp.
The connection will be made over sockets so the focus remains on http



## Install and run the project
To use, install make sure a c++ compiler and cmake are installed

Build the project
```bash
make build
```


Run the server
```bash
make server
```


Run the client
```bash
make client
```

All c++ code is found in the src folder and header files are found in the include folder

Research: https://developer.mozilla.org/en-US/docs/Web/HTTP/Guides/Evolution_of_HTTP