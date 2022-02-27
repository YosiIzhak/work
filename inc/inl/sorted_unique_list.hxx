#include <iostream>
#include <cassert>
#include "sorted_unique_list.hpp"
#include <list>
#include <cstdio>

namespace cpp
{

template<typename T>
SortedUniqueList<T>::SortedUniqueList()
: SortedContainer<T>()
, m_list()
{}

template<typename T>
SortedUniqueList<T>::~SortedUniqueList(){}

template<typename T>
void SortedUniqueList<T>::insert(value_type a_item)
{
    if(contains(a_item))
    {
        return;
    }
    Itr it = m_list.begin(); 
    Itr end = m_list.end();
    while(it != end)
    {
        if(a_item < *it)
        {
            m_list.insert(it , a_item);
            return;
        }
        ++it;
    }
    m_list.push_back(a_item);
}

template<typename T>
size_t SortedUniqueList<T>::remove(value_type a_item)
{
    Itr it = m_list.begin(); 
    Itr end = m_list.end();
    size_t count = 0;
    while(it != end)
    {
        if(a_item == *it)
        {
            m_list.erase(it++);
            if(it != end--)
            {
                --it;  
            }
            count += 1;
        }
        ++it;
    }
    return count;
}

template<typename T>
size_t SortedUniqueList<T>::contains(value_type a_item)const
{
    ConstItr it = m_list.begin(); 
    ConstItr end = m_list.end();
    size_t count = 0;
    while(it != end)
    {
        if(a_item == *it)
        {
            count += 1;
        }
        ++it;
    }
    return count;
}

template<typename T>
typename SortedUniqueList<T>::value_type SortedUniqueList<T>::front() const
{
    return m_list.front();
}

template<typename T>
typename SortedUniqueList<T>::value_type SortedUniqueList<T>::back() const
{
    return m_list.back();
}

template<typename T>
std::ostream& SortedUniqueList<T>::print(std::ostream& a_ostream)const
{
    return printContainer(m_list, a_ostream);
}

template<typename T>
size_t SortedUniqueList<T>::size()const
{
    return m_list.size();
}

template<typename T>
typename SortedUniqueList<T>::value_type SortedUniqueList<T>::median()const
{
    return containerMedian(m_list);
}

template<typename T>
bool SortedUniqueList<T>::isSorted() const
{
    return isContainerSorted(m_list);
}

template<typename T>
bool SortedUniqueList<T>::isUniform()const
{
    return isContainerUniform(*this);
}

template<typename T>
MyIterator<T> SortedUniqueList<T>::begin()const 
{
    return &m_list.front();
}

template<typename T>
MyIterator<T> SortedUniqueList<T>::end()const 
{
   MyIterator<T> last = &m_list.back();
   ++last;
   return last;
}


} //cpp namespace