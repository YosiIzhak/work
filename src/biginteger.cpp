#include "biginteger.hpp"
#include "single_list.hpp"
#include "hashset.hpp"
#include <cstddef>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>


BigInteger::BigInteger()
:m_list()
,m_sign(1)
,m_numOfDigits(0)
{
   
}
BigInteger::BigInteger(long a_num)
:m_list()
,m_sign(1)
,m_numOfDigits(0)
{
   int digit;
   while (a_num > 0)
   {
       digit = a_num % 10;
       m_list.add(digit);
       m_numOfDigits++;
       a_num = a_num/ 10;
       if (a_num < 0)
       {
           m_sign = -1;
       }
   }
    m_list = this->flip();
}
BigInteger::BigInteger(const char* a_str)
:m_list()
,m_sign(1)
{
    char curr;
    int digit;
   
   if (*a_str == '-')
   {
       m_sign = -1;
       a_str++;
   }
   while (*a_str)
   {
       curr = *a_str - '0';
       if (curr < 0 || curr > 9)
       {
          break;
       }
      else
      {
        digit = curr;
        m_list.add(digit);
        m_numOfDigits++;
        a_str++;
      }
     
   }
}
BigInteger& BigInteger::operator=(long const& a_source)
{
  BigInteger newBig(a_source);
  *this = newBig;
  return *this;
}
char& BigInteger::getSign()
{
  return m_sign;
}
char BigInteger::setSignMul(BigInteger const& a_integer)
{
  if (m_sign == 1 && a_integer.m_sign == -1)
  {
    return -1;
  }
  if (m_sign == -1 && a_integer.m_sign == 1)
  {
    return -1;
  }
  else 
  {
    return 1;
  }
}
LinkedList& BigInteger::getList()
{
    return m_list;
}
LinkedList BigInteger::flip() 
{
    LinkedList flipped;
    Iterator it = m_list.begin();
    Iterator end = m_list.end();

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
    if (m_sign == -1)
    {
       printf("- ");
    }
    while (it.notEqual(end))
    {
       printf("%d ",it.data());
        it = it.next();
    }
}
bool BigInteger::equal(BigInteger const& a_num) const
{
  if (m_sign != a_num.m_sign)
  {
    return false;
  }
  if (m_numOfDigits != a_num.m_numOfDigits)
  {
    return false;
  }
   BigInteger first = *this;
   BigInteger second = a_num;
   Iterator firstIt = first.m_list.begin();
   Iterator secIt = second.m_list.begin();
   Iterator firstEnd = first.m_list.end();
  
   while (firstIt.notEqual(firstEnd)) 
   {
     if (firstIt.data() != secIt.data())
     {
       return false;
     }
     firstIt.next();
     secIt.next();
   }
  return true;
}
bool BigInteger::notEqual(BigInteger const& a_num) const
{
  return !equal(a_num);
}
bool BigInteger::less(BigInteger const& a_num) const
{
  if (m_sign == 1 && a_num.m_sign == -1)
  {
    return false;
  }
  if (m_sign == -1 && a_num.m_sign == 1)
  {
    return true;
  }
  if (m_numOfDigits > a_num.m_numOfDigits)
  {
    return false;
  }
  if (m_numOfDigits < a_num.m_numOfDigits)
  {
    return true;
  }
   BigInteger first = *this;
   BigInteger second = a_num;
   first.m_list = first.flip();
   second.m_list = second.flip();
   Iterator firstIt = first.m_list.begin();
   Iterator secIt = second.m_list.begin();
   Iterator firstEnd = first.m_list.end();
  
   while (firstIt.notEqual(firstEnd))
   {
     if (firstIt.data() > secIt.data())
     {
       return false;
     }
      if (firstIt.data() < secIt.data())
     {
       return true;
     }
      firstIt.next();
      secIt.next();
   }
   return false;
}
bool BigInteger::greater(BigInteger const& a_num) const
{
  if (equal(a_num) || less(a_num))
  {
    return false;
  }
  return true;
}
bool BigInteger::equalOrGreater(BigInteger const& a_num) const
{
  if (equal(a_num) || greater(a_num))
  {
    return true;
  }
  return false;
}
bool BigInteger::lessOrEqual(BigInteger const& a_num) const
{
  if (equal(a_num) || less(a_num))
  {
    return true;
  }
  return false;
}

BigInteger& BigInteger::add(BigInteger const& a_num) 
{
  LinkedList sumList;
  int carry = 0, sum = 0;
  Iterator firstIt = m_list.begin();
  Iterator secIt = a_num.m_list.begin();
  Iterator firstEnd = m_list.end();
  Iterator secEnd = a_num.m_list.end();
  while (firstIt.notEqual(firstEnd) || secIt.notEqual(secEnd)) 
  {
    sum = carry;
    sum += firstIt.data();
    //printf("%d firstIt:\n", sum);
    sum += secIt.data();
   // printf("%d secIt:\n", sum);
    if (sum >= 10)
    {
      carry = 1;
    } 
    else 
    {
      carry = 0;
    }
    sum %= 10;
    sumList.add(sum);

   // printf("%d sum:\n", sum);
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
       sumList.add(carry);
  }
  
   m_list = sumList;
  return *this;
}

BigInteger& BigInteger::mul(BigInteger const& a_num) 
{
  BigInteger newSum = *this;
  BigInteger second = a_num;
  int carry = 0, mult = 0, count = 0;
  BigInteger res, temp;
  Iterator firstIt = newSum.m_list.begin();
  Iterator secIt = second.m_list.begin();
  Iterator firstEnd = newSum.m_list.end();
  Iterator secEnd = second.m_list.end();
  newSum.m_sign = setSignMul(a_num);
  while (firstIt.notEqual(firstEnd)) 
  {
      secIt = second.m_list.begin();
     
      for (int i = 0; i < count; i++)
      {
        temp.m_list.add(0);
      // printf("%d**\n", count);
      }
      while(secIt.notEqual(secEnd))
      {
        mult = carry;
        mult += (firstIt.data() * secIt.data());
        carry = mult /10;
        mult %= 10;
        secIt = secIt.next();
        temp.m_list.add(mult);
      }
      if (carry > 0)
      {
       temp.m_list.add(carry);
      }
    
      temp.m_list = temp.flip();
      res.add(temp);
      res.m_list = res.flip();
      size_t k = res.m_list.size();
      for (size_t j = 0; j < k; j++)
      {
          temp.m_list.remove();
      }
      firstIt = firstIt.next();
      count++;
  }
  res.m_list = res.flip();
  m_list = res.m_list;
  return *this;
}
   
BigInteger add(BigInteger const& a_integer, long const& a_num)
{
  BigInteger first = a_integer;
  first.add(a_num);
  return first;
}
BigInteger mul(BigInteger const& a_integer, long const& a_num)
{
  BigInteger first = a_integer;
   first.mul(a_num);
  return first;
}
bool equal(BigInteger const& a_first, long const& a_second)
{
  BigInteger first = a_first;
  return first.equal(a_second);
}
bool notEqual(BigInteger const& a_first, long const& a_second)
{
   BigInteger first = a_first;
   return first.notEqual(a_second);
}
bool less(BigInteger const& a_first, long const& a_second)
{
   BigInteger first = a_first;
   return first.less(a_second);
}
bool greater(BigInteger const& a_first, long const& a_second)
{
    BigInteger first = a_first;
   return first.greater(a_second);
}
bool equalOrGreater(BigInteger const& a_first, long const& a_second)
{
    BigInteger first = a_first;
    return first.equalOrGreater(a_second);
} 
bool lessOrEqual(BigInteger const& a_first, long const& a_second)
{
    BigInteger first = a_first;
   return first.lessOrEqual(a_second);
}