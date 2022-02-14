#include "socket.hpp"
#include <arpa/inet.h>
#include <cstring>


struct Message
{
    int id;
    double speed;
    double altitude;
};

int sendMessage(TCP::ClientSoc const& a_soc, struct Message const* a_message)
{
    uint32_t id = htobe32(a_message->id);
    uint64_t alt = htobe64(a_message->altitude);
    uint64_t speed = htobe64(a_message->speed);

    size_t totalSize = 2*sizeof(uint64_t) + sizeof(uint32_t);
    char* serializedMessage = new char[totalSize];
    char* ptr = serializedMessage;

    
    memcpy(ptr,&speed,sizeof(uint64_t));
    ptr += sizeof(uint64_t);

    memcpy(ptr,&alt,sizeof(uint64_t));
    ptr += sizeof(uint64_t); 

    memcpy(ptr,&id,sizeof(uint32_t));
    ptr += sizeof(uint32_t);


    int result = a_soc.send(serializedMessage,totalSize);
    delete[] serializedMessage;

    return result;
}



/* #include <cstdio>
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
} */