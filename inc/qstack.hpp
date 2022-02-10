#ifndef QSTACK_HPP__
#define QSTACK_HPP__
#include <cstddef> 
#include "queue.hpp"
namespace Cppp {

template <typename T>
class Qstack
{
public:
    Qstack(size_t a_size = 64);
    Qstack(Qstack const& a_source);
    Qstack& operator=(Qstack const& a_source);
    ~Qstack();
    void enqueue(T const& item);
    T dequeue();
    bool isEmpty() const;
    bool isFull() const;
    size_t size() const;
    void clear();
   

private:
    size_t m_capacity;
    size_t m_size;
    Queue m_in;
    Queue m_out;

};
}
#include "./inl/queue.hxx"
#include "./inl/qstack.hxx"

#endif