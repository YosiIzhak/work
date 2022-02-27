#ifndef SORTED_UNIQUE_VECTOR_HPP
#define SORTED_UNIQUE_VECTOR_HPP

#include <iostream>
#include <cassert>
#include <vector>
#include "sorted_container.hpp"

namespace cpp
{

template<typename T>
class SortedUniqueVector: public SortedContainer<T>
{
public:
    typedef T value_type;
    SortedUniqueVector(size_t a_size = 64);
    ~SortedUniqueVector();

    void insert(value_type a_item);
    size_t remove(value_type a_item);

    size_t contains(value_type a_item)const;
    size_t size()const;
    value_type front() const;
    value_type back() const;

    std::ostream& print(std::ostream& a_ostream = std::cout)const;
    void fill(value_type a_item, size_t a_times);

    value_type median()const;
    bool isSorted()const;
    bool isUniform()const;

    MyIterator<value_type> begin()const; 
    MyIterator<value_type> end()const; 

private:
    typedef std::vector<T> Container;
    typedef typename Container::const_iterator ConstItr;
    typedef typename Container::iterator Itr;
    Container m_vector;
};


} //cpp namespace

#include "./inl/sorted_unique_vector.hxx"

#endif  // SORTED_UNIQUE_VECTOR_HPP