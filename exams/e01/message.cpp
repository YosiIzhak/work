#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <sys/socket.h>
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


void sendMesege(int a_socketId, struct Message* a_message)
{
   char* buffer = new char[sizeof(a_message)+1];
   int length = wrapMessage(a_message, buffer);
   send(a_socketId, buffer, length, 0);
}