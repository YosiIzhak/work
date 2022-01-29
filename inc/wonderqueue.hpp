#ifndef _WONDERQUEUE_HPP_
#define _WONDERQUEUE_HPP_
#include "stack.hpp"
  
         
        
class WonderQueue
{
public:
    //special member functions
    //Constructor, ctor
    WonderQueue(size_t n);
   
    // member functions
   
    //mutators:
   
    void enqueue(int x);
    int dequeue();
   
    //accessors
    size_t capacity() const;
    size_t size() const;
    bool isEmpty() const;
    bool isFull() const;
    void dump() const;
    
private: //private functions
    void dumpElements() const;
    void axioms() const;
    // data member
private: //struct members
     Stack  m_firstStack;
     Stack  m_secondStack;
     size_t  m_capacity;
     size_t  m_size;
   
};



#endif //_WONDERQUEUE_HPP_
