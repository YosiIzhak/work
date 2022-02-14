#ifndef WonderStack_HPP__
#define WonderStack_HPP__
#include <cstddef> 
#include "queue.hpp"
namespace Cpp {

template <typename T>
class WonderStack
{
public:
    WonderStack(size_t a_size = 64);
    
    void push(T const& item);
    T pop();
    
    T top() const;
    bool isEmpty() const;
    bool isFull() const;
    size_t size() const;
    void clear();
   

private:
    size_t m_capacity;
    size_t m_size;
    Queue<T> m_in;
    Queue<T> m_out;

};
}
#include "./inl/queue.hxx"
#include "./inl/wonder_stack.hxx"

#endif