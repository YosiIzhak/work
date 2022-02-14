#ifndef BIG_INTEGER_HPP
#define BIG_INTEGER_HPP

#include <cstddef>
#include "single_list.hpp"

class BigInteger
{
public:
  BigInteger();
  BigInteger(long a_num);
  explicit BigInteger(const char* a_str);
  BigInteger &operator=(long const& a_source);
 ~BigInteger();
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
bool equal(BigInteger const& a_num) const;
bool notEqual(BigInteger const& a_num) const;
bool less(BigInteger const& a_num) const;
bool greater(BigInteger const& a_num) const;
bool equalOrGreater(BigInteger const& a_num) const; 
bool lessOrEqual(BigInteger const& a_num) const;
private:
  
    LinkedList m_list;
    char m_sign;
    size_t m_numOfDigits;
};

BigInteger add(BigInteger const& a_integer, long const& a_num);
BigInteger mul(BigInteger const& a_integer, long const& a_num); 
bool equal(BigInteger const& a_first, long const& a_second);
bool notEqual(BigInteger const& a_first, long const& a_second);
bool less(BigInteger const& a_first, long const& a_second); 
bool greater(BigInteger const& a_first, long const& a_second); 
bool equalOrGreater(BigInteger const& a_first, long const& a_second);
bool lessOrEqual(BigInteger const& a_first, long const& a_second); 
#endif  // LINKED_LIST_HPP