#ifndef BIG_INTEGER_HPP
#define BIG_INTEGER_HPP

#include <cstddef>


class bigInteger
{
public:
    bigInteger();
   
   
   
    
  

    bigInteger add();
    bigInteger sub();
   
private:
    void axioms();    
  
private:
    Node* m_sentinal;
    Node * m_head;
    Node * m_tail;
    size_t m_size;
};


#endif  // LINKED_LIST_HPP