#include "sortedVector.hpp"
#include "hashset.hpp"
#include <cstddef>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include "sortedContainer.hpp"

void SortedVector::insert(int x)
{
    std::vector<int>::iterator it;
    for (it= m_vec.begin(); it < m_vec.end(); ++it)
    {
        if ((*it) > x)
        {
            m_vec.insert(it, x);
            break;
        }
    }
   
    //m_vec.push_back(x);
    //std::sort (m_vec.begin(), m_vec.end()); 
}

  bool SortedVector::contains(int x)
  {
        std::vector<int>::iterator it;
        it = find (m_vec.begin(), m_vec.end(), x);
        if (it != m_vec.end())
        {
            return true;
        }
        else
        {
            return false;
        }
  }

   void SortedVector::remove(int x)
   {
      for (size_t i = 0; i < m_vec.size(); ++i)
      {
         if(m_vec[i] == x)
         {
             m_vec.erase(m_vec.begin()+i);
             i--;
         } 
      }
   }

  
int SortedVector::front()
{
    return m_vec.front();
}

int SortedVector::back()
{
    return m_vec.back();
}

std::ostream& print(std::ostream& a_ostream)
{
    for (size_t i = 0; i < m_vec.size(); ++i)
      {
         a_ostream << m_vec[i << ' ';]
      }
      a_ostream << '\n';
}
