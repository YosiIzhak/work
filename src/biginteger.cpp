#include "biginteger.hpp"
#include "single_list.hpp"
#include <cstddef>
#include <cassert>
#include <cstdio>
#include <cstring>


BigInteger::BigInteger()
:m_list()
{
   
}
BigInteger::BigInteger(long a_num)
:m_list()
{
   int digit;
   while (a_num > 0)
   {
       digit = a_num % 10;
       m_list.add(digit);
       a_num = a_num/ 10;
      
       m_list = this->flip();
   }
}
LinkedList BigInteger::getList()
{
    return m_list;
}
LinkedList BigInteger::flip() 
{
    LinkedList flipped;
    Iterator it = m_list.begin();
    Iterator end = m_list.end();

    if(m_list.size() <= 1)
    {
        return m_list;
    }
    
    while(it.notEqual(end))
    {
        flipped.add(it.data());
        it = it.next();
    } 

    return flipped;  
}
void BigInteger::printList()
{
    Iterator it = this->m_list.begin();
    Iterator end = this->m_list.end();
    while (it.notEqual(end))
    {
       printf("%d, ",it.data());
        it = it.next();
    }
}
BigInteger BigInteger::add(BigInteger const& a_num) 
{
  BigInteger newSum;
  int carry = 0, sum = 0;
  Iterator firstIt = this->m_list.begin();
  Iterator secIt = a_num.m_list.begin();
  Iterator firstEnd = this->m_list.end();
  Iterator secEnd = a_num.m_list.end();
  while (firstIt.notEqual(firstEnd) || secIt.notEqual(secEnd)) 
  {
    sum = carry;
    sum += firstIt.data();
    sum += secIt.data();
    if (sum >= 10)
    {
      carry = 1;
    } 
    else 
    {
      carry = 0;
    }
    sum %= 10;
    newSum.m_list.add(sum);
    if (firstIt.notEqual(firstEnd))
    {
      firstIt = firstIt.next();
    }
    if (secIt.notEqual(secEnd)) 
    {
      secIt = secIt.next();
    }
  }
  if (carry > 0)
  {
       newSum.m_list.add(carry);
  }
  LinkedList temp = newSum.flip();
  newSum.m_list = temp;
  return newSum;
}

BigInteger BigInteger::mul(BigInteger const& a_num) 
{
  BigInteger newSum;
  int carry = 0, mult = 0, count = 0;
  Iterator firstIt = this->m_list.begin();
  Iterator secIt = a_num.m_list.begin();
  Iterator firstEnd = this->m_list.end();
  Iterator secEnd = a_num.m_list.end();
  while (firstIt.notEqual(firstEnd)) 
  {
      secIt = a_num.m_list.begin();
      BigInteger temp;
      for (int i = 0; i < count; i++)
      {
        temp.m_list.add(0);
        printf("%d**\n", count);
      }
      while(secIt.notEqual(secEnd))
      {
        mult = carry;
        mult += (firstIt.data() * secIt.data());
        carry = mult /10;
        mult %= 10;
        secIt = secIt.next();
        printf("%d\n", mult);
        temp.m_list.add(mult);
      }
      if (carry > 0)
      {
       temp.m_list.add(carry);
      }
      newSum.add(temp);
      for (size_t j = 0; j < temp.m_list.size(); j++)
      {
          temp.m_list.remove();
      }
      firstIt = firstIt.next();
      count++;
  }
 
  return newSum;
}    