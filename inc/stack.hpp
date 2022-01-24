#ifndef _STACK_HPP_
#define _STACK_HPP_


class Stack
{
public:
    //special member functions
    //Constructor, ctor
    Stack(size_t n);
    // member functions
    //mutators:
    void push(int x);
    int pop();
    //accessors
    size_t size() const;
    bool isEmpty() const;
    bool isFull() const;
    void dump() const;
    void empty(); //empties stack
    
private: //private functions
    void dumpElements() const;
    void axioms() const;
    // data member
private: //struct members
    int* m_elements;
    size_t m_tos;
    size_t m_capacity;
};

#endif //_STACK_HPP_
