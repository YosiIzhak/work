#ifndef SOCKET_H
#define SOCKET_H
#include <cstdlib> 

class Socket
{
public:
    Socket(size_t a_size);
    ~Socket();
    Socket(Socket const &source);
    Socket &operator=(Socket const &source);
    void sendMessage(char* a_buffer, int a_socketId, size_t a_len);
    void receiveMessage(char* a_buffer, int a_socketId, size_t a_len);
    void clientSend(char* a_buffer, int a_length);
private:
    int m_ip;
    int m_socketId;
};


#endif