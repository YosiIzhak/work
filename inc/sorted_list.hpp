#ifndef SORTED_LIST_HPP
#define SORTED_LIST_HPP

#include <iostream>
#include <cassert>
#include <list>
#include "sorted_container.hpp"

namespace cpp
{

template<typename T>
class SortedList: public SortedContainer<T>
{
public:
    typedef T value_type;
    SortedList();
    ~SortedList();

    void insert(value_type a_item);
    size_t remove(value_type a_item);

    size_t contains(value_type a_item) const;
    size_t size()const;
    value_type front() const;
    value_type back() const;

    std::ostream& print(std::ostream& a_ostream = std::cout) const;

    value_type median()const;
    bool isSorted() const;
    bool isUniform()const;

    MyIterator<value_type> begin()const;
    MyIterator<value_type> end()const; 

private:
    typedef std::list<T> Container;
    typedef typename Container::const_iterator ConstItr;
    typedef typename Container::iterator Itr;
    Container m_list;
};


} //cpp namespace

#include "./inl/sorted_list.hxx"

#endif  // SORTED_LIST_HPP