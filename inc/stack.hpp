#ifndef _STACK_HPP_
#define _STACK_HPP_


class Stack
{
public:
    //special member functions
    //Constructor, ctor
    Stack(size_t n);
    Stack(int a_arr[], size_t a_size);
    Stack(int a_arr[], size_t a_fromArr, size_t a_size);
    // member functions
    ~Stack();
    //mutators:
    void push(int const* x, size_t arrSize);
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
    int* m_elements;
    size_t m_tos;
    size_t m_capacity;
};

Stack combine(Stack &a_first, Stack &a_second);

#endif //_STACK_HPP_
