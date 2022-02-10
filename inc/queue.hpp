#ifndef QUEUE_HPP__
#define QUEUE_HPP__
#include <cstddef> 

namespace Cpp {

template <typename T>
class Queue
{
public:
    Queue(size_t a_size = 64);
    Queue(Queue const& a_source);
    Queue& operator=(Queue const& a_source);
    ~Queue();
    void enqueue(T const& item);
    T dequeue();
    bool isEmpty() const;
    bool isFull() const;
    size_t size() const;
    void clear();
   

private:
    size_t m_capacity;
    T* m_arr;
    size_t m_size;
    size_t m_head;
    size_t m_tail;

};
}
#include "./inl/queue.hxx"

#endif