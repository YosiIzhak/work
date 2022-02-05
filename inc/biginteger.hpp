#ifndef BIG_INTEGER_HPP
#define BIG_INTEGER_HPP

#include <cstddef>
#include "single_list.hpp"

class BigInteger
{
public:
  BigInteger();
  BigInteger(long a_num);
  BigInteger(const char* a_str);
 char& getSign();
 char setSignMul(BigInteger const& a_integer);
 BigInteger& add(BigInteger const& a_integer); 
 BigInteger sub(BigInteger a_integer); 
 BigInteger& mul(BigInteger const& a_integer); 
 char* toString();

 Node * solve(Node * list1, Node * list2);
 void printList();
LinkedList& getList();
LinkedList flip();
    
private:
  
    LinkedList m_list;
    char m_sign;
};

 
#endif  // LINKED_LIST_HPP