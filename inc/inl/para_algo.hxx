#ifndef PARA_ALGO_HXX
#define PARA_ALGO_HXX

#include <iostream>
#include <algorithm>
namespace cpp
{

template<typename T>
struct Arg
{
    Arg(std::vector<T> const& a_vec = 0, size_t a_from = 0, size_t a_end = 0)
    : m_vec(a_vec)
    , m_from(a_from)
    , m_end(a_end)
    {}

    std::vector<T> const& m_vec;
    size_t m_from;
    size_t m_end;
    
};

template<typename T>
void* sumElemnts(void* a_arg)
{
    Arg<T>* arg = static_cast<Arg<T>*>(a_arg);

    if(0 == arg)
    {   
        return 0;
    }     

    size_t from = arg->m_from;
    size_t end = arg->m_end; 
    std::vector<T> const& vec = arg->m_vec;

    T* sum = new T;
    for(size_t i = from; i < end; ++i)
    {
        *sum += vec[i];
    }

    return sum;  
}

template<typename T>
void* sortElemnts(void* a_arg)
{
    Arg<T>* arg = static_cast<Arg<T>*>(a_arg);

    if(0 == arg)
    {   
        return 0;
    }     
   
    size_t from = arg->m_from;
    size_t end = arg->m_end; 
    std::vector<T> const& vec = arg->m_vec;
    std::vector<T>::iterator it = &vec[from];
    std::vector<T>::iterator itEnd = &vec[end];
    std::sort (it, itEnd);
    return static_cast<void*>(arg);
}

template<typename T>
size_t sumVector(std::vector<T> const& a_vec, size_t a_numOfThreads)
{
    size_t part = a_vec.size()/ a_numOfThreads;
    size_t start = 0;
    size_t end = part;
    size_t sum = 0;
   
    for(size_t i = 0; i < a_numOfThreads; ++i)
    {
       pthread_t thread;
       void* r;
       cpp::Arg<T>* arg = new cpp::Arg<T>(a_vec, start, end);
       ::pthread_create(&thread, 0, sortElemnts<T>,  static_cast<void*>(arg));
       ::pthread_join(thread, &r);
       sum += *static_cast<size_t*>(r); 
       start = end;
       end = end +part; 
    }
    return sum;
}

template<typename T>
size_t sortVector(std::vector<T> const& a_vec, size_t a_numOfThreads)
{
    size_t part = a_vec.size()/ a_numOfThreads;
    size_t start = 0;
    size_t end = part;
    std::vector<T> temp(2 * part);
    for(size_t i = 0; i < a_numOfThreads; ++i)
    {
       pthread_t thread;
       void* r;
       cpp::Arg<T>* arg = new cpp::Arg<T>(a_vec, start, end);
       ::pthread_create(&thread, 0, sortElemnts<T>,  static_cast<void*>(arg));
       ::pthread_join(thread, &r);
        start = end;
        end = end +part; 
    }
    return sum;
}


}//namespace cpp

#endif//PARA_ALGO_HXX