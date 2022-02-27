#include <iostream>
#include <cassert>


namespace cpp
{

template<typename T>
MyIterator<T>::MyIterator(T const* x) :p(x) {}
template<typename T>
MyIterator<T>::MyIterator(const MyIterator<T>& mit) : p(mit.p) {}
template<typename T>
MyIterator<T>& MyIterator<T>::operator++() {++p;return *this;}
template<typename T>
MyIterator<T> MyIterator<T>::operator++(int) {MyIterator<T> tmp(*this); operator++(); return tmp;}
template<typename T>
bool MyIterator<T>::operator==(const MyIterator<T>& rhs) const {return p==rhs.p;}
template<typename T>
bool MyIterator<T>::operator!=(const MyIterator<T>& rhs) const {return p!=rhs.p;}
template<typename T>
T MyIterator<T>::operator*() const {return *p;}

template<typename T>
SortedContainer<T>::SortedContainer(){}

template<typename T>
SortedContainer<T>::~SortedContainer(){}

template<typename T>
void SortedContainer<T>::fill(value_type a_value, size_t a_times)
{
    while(a_times-- > 0)
    {
        insert(a_value);
    }
}

template<typename T>
bool SortedContainer<T>::empty()const
{
    return size() == 0;
}

template<typename T>
std::ostream& operator<<(std::ostream& a_ostream, SortedContainer<T> const& a_container)
{
    return a_container.print(a_ostream);
}

template <typename T>
std::ostream& printContainer(T const& a_container, std::ostream& a_ostream)
{
    typename T::const_iterator it = a_container.begin(); 
    typename T::const_iterator end = a_container.end();  
   
    a_ostream << '{';
    if(it != end)
    {
        a_ostream << *it++;  
    }
    while(it != end)
    {
        a_ostream << ", " << *it++; 
    }
    a_ostream << "}\n"; 

    return a_ostream;
} 

template <typename T>
typename T::value_type containerMedian(T const& a_container)
{
    typename T::const_iterator it = a_container.begin(); 
    size_t med = a_container.size()/2;
    for(size_t i = 0; i < med; ++i)
    {
        ++it;
    }
    return *it;
}

template <typename T>
bool isContainerSorted(T const& a_container)
{
    typename T::const_iterator prev = a_container.begin();
    typename T::const_iterator it = a_container.begin();
    typename T::const_iterator end = a_container.end();
    ++it;
    while(it != end)
    {
        if(*it < *prev)
        {
            return false;
        }
        ++it;
        ++prev;
    } 
    return true;
}


} //cpp namespace