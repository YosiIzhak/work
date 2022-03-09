#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <vector>
#include "vector2.hpp"



MyVector::MyVector(size_t a_size)
: m_size(a_size)
{
  m_vector = std::vector<int>(a_size);
}


int MyVector::sum(int const& begin, int const& end) const
{
   size_t sum = 0;
   for (size_t i = begin; i < end; ++i)
   {
      sum += m_vector[i];
   }
}   
 
void MyVector::update(int const& index, int const value)
{
    m_vector[index] = value;
}

