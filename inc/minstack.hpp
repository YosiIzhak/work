#ifndef _STACK_HPP_
#define _STACK_HPP_

#include "stack.hpp"
class minStack
{
public:
    //special member functions
    //Constructor, ctor
    minStack(size_t n);
   
    // member functions
    ~minStack();
    //mutators:
    void push(int* x, size_t arrSize);
     void push(int x);
    int* pop(int a_arr[], size_t a_arrSize);
    int pop();
    void drain(Stack* a_source);
   void ensureCapacity(size_t a_cap);
    //accessors
    size_t capacity() const;
    size_t size() const;
    bool isEmpty() const;
    bool isFull() const;
    void dump() const;
    int top() const;
    void empty(); //empties stack
    Stack(const Stack &a_stack);
private: //private functions
    void dumpElements() const;
    void axioms() const;
    // data member
private: //struct members
    Stack*   m_stack;
    int* m_elements;
    size_t m_tos;
    size_t m_capacity;
};

minStack combine(Stack &a_first, Stack &a_second);

#endif //_STACK_HPP_
