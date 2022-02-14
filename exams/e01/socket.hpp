#ifndef CLIENT_TCP_SOCKET_HPP
#define CLIENT_TCP_SOCKET_HPP

#include <netinet/in.h>

namespace TCP
{

class ClientSoc
{
public:
    ClientSoc(int a_port, char const* a_IP);
    ~ClientSoc();

    int send(char* a_data, size_t a_size) const;
    int receive(char* a_buffer, size_t a_bufferSize) const;
    int soc() const;

private:
    char const* m_IP;
    char const m_port;
    int m_soc;
    sockaddr_in m_sin;
};


}//TCP

#endif //CLIENT_TCP_SOCKET_HPP


/* #ifndef SOCKET_H
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


#endif */