#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include "socket.hpp"

struct Message{
 int id;
 double speed;
 double altitude;
};

int wrapMessage(struct Message* a_struct, char* a_buffer)
{
    memcpy(a_buffer, a_struct, sizeof(a_struct));
    return  sizeof(a_struct);
}


void sendMesege(Socket a_socket, struct Message* a_message)
{
   char* buffer = new char[sizeof(a_message)+1];
   int length = wrapMessage(a_message, buffer);
   a_socket.clientSend(buffer, length);
}