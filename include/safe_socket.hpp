#pragma once
#include <unistd.h>

class SafeSocket {
    int conn;
public:
    explicit SafeSocket(int conn) : conn(conn) {}
    ~SafeSocket() {
        if (conn >= 0) {
            close(conn);
        }
    }

    int get() const { return conn; }

    // No copy allowed
    SafeSocket(const SafeSocket&) = delete;
    SafeSocket& operator=(const SafeSocket&) = delete;
};