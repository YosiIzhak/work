#ifndef SORTED_CONTAINER_HPP
#define SORTED_CONTAINER_HPP

#include <iostream>
#include <cassert>

namespace cpp
{

template<typename T>
class MyIterator : public std::iterator<std::input_iterator_tag, T>
{
public:
    typedef T value_type;
    MyIterator(value_type const* x);
    MyIterator(const MyIterator& mit);
    MyIterator& operator++();
    MyIterator operator++(int);
    bool operator==(const MyIterator& rhs)const;
    bool operator!=(const MyIterator& rhs)const;
    value_type operator*()const;

private:
    value_type const* p;
};

template<typename T>
class SortedContainer
{
public:
    typedef T value_type;
    SortedContainer();
    virtual ~SortedContainer() = 0; 

    virtual void insert(value_type a_item) = 0;
    virtual size_t remove(value_type a_item) = 0;
    
    virtual size_t contains(value_type a_item)const = 0;
    virtual value_type front() const = 0;
    virtual value_type back() const = 0;
    virtual std::ostream& print(std::ostream& a_ostream)const = 0;
    virtual size_t size() const = 0;

    virtual MyIterator<T> begin()const = 0; 
    virtual MyIterator<T> end()const = 0;

    virtual void fill(value_type a_item, size_t a_times);
    bool empty()const;

private:
    SortedContainer& operator=(SortedContainer const& a_container);
    SortedContainer(SortedContainer const& a_container);
};

template<typename T>
inline
bool isContainerUniform(cpp::SortedContainer<T> const& a_container)
{
    MyIterator<T> prev(a_container.begin());
    MyIterator<T> it (a_container.begin());
    MyIterator<T> end (a_container.end());
    ++it;
    while(it != end)
    {
        if(!(*prev == *it))
        {
           return false;  
        }
        ++it;
        ++prev;
    }
    return true;
} 

template<typename T>
bool isContainerSorted(T const& a_container);

template<typename T>
typename T::value_type containerMedian(T const& a_container);

template <typename T>
std::ostream& printContainer(T const& a_container, std::ostream& a_ostream = std::cout);

template<typename T>
inline bool empty(SortedContainer<T> const& a_container){return a_container.size() == 0;}

template<typename T>
std::ostream& operator<<(std::ostream& a_ostream, SortedContainer<T>  const& a_container);


} //cpp namespace

#include "./inl/sorted_container.hxx"

#endif  // SORTED_CONTAINER_HPP