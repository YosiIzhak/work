#include <iostream>
#include <cassert>
#include "sorted_unique_vector.hpp"
#include <cstdio>

namespace cpp
{

template<typename T>
SortedUniqueVector<T>::SortedUniqueVector(size_t a_size)
: SortedContainer<T>()
, m_vector()
{
    m_vector.reserve(a_size);
}

template<typename T>
SortedUniqueVector<T>::~SortedUniqueVector(){}

template<typename T>
void SortedUniqueVector<T>::insert(value_type a_item)
{
    if(contains(a_item))
    {
        return;
    }
    size_t size = m_vector.size();
    for(size_t i = 0; i < size; i++)
    {
        if(a_item < m_vector[i])
        {
            m_vector.insert(m_vector.begin() + i, a_item);
            return;
        }
    }
    m_vector.push_back(a_item);
}

template<typename T>
size_t SortedUniqueVector<T>::remove(value_type a_item)
{
    size_t size = m_vector.size();
    size_t count = 0;
    for(size_t i = 0; i < size; ++i)
    {
        if(a_item == m_vector[i])
        {
            m_vector.erase(m_vector.begin() + i);
            if(i != size - 1)
            {
                --i;  
            }
            ++count;
        }
    }
    return count;
}

template<typename T>
size_t SortedUniqueVector<T>::contains(value_type a_item)const
{
    ConstItr end = m_vector.end();
    ConstItr it = std::lower_bound(m_vector.begin(), m_vector.end(), a_item);
    size_t count = 0;
    while(it != end && *it == a_item)
    {
        ++count;
        ++it;
    }
    return count;
}

template<typename T>
typename SortedUniqueVector<T>::value_type SortedUniqueVector<T>::front() const
{
    return m_vector.front();
}

template<typename T>
typename SortedUniqueVector<T>::value_type SortedUniqueVector<T>::back() const
{
    return m_vector.back();
}

template<typename T>
std::ostream& SortedUniqueVector<T>::print(std::ostream& a_ostream)const
{
    return printContainer(m_vector, a_ostream);
}

template<typename T>
size_t SortedUniqueVector<T>::size()const
{
    return m_vector.size();
}

template<typename T>
void SortedUniqueVector<T>::fill(value_type a_item, size_t a_times)
{
    if(contains(a_item))
    {
        return;
    }
    Itr it = std::lower_bound(m_vector.begin(), m_vector.end(), a_item);
    m_vector.insert(it, a_times, a_item);
}

template<typename T>
typename SortedUniqueVector<T>::value_type SortedUniqueVector<T>::median() const
{
    return containerMedian(m_vector);
}

template<typename T>
bool SortedUniqueVector<T>::isSorted() const
{
    return isContainerSorted(m_vector);
}

template<typename T>
bool SortedUniqueVector<T>::isUniform()const
{
    return isContainerUniform(*this);
}

template<typename T>
MyIterator<T> SortedUniqueVector<T>::begin()const
{
   MyIterator<T> first(&m_vector[0]);
   return first;
}

template<typename T>
MyIterator<T> SortedUniqueVector<T>::end()const 
{
   MyIterator<T> last(&m_vector[size()]);
   return last;
}

} //cpp namespace