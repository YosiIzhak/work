#ifndef STACK_HPP
#define STACK_HPP
#include <cstdlib> //size_t

class Stack
{
public:
	//constructors
	Stack(size_t a_capacity = 64);
    Stack(int const *a_array, size_t a_arrSize);   
    Stack(int const *a_array, size_t a_arrSize, size_t a_nItems, size_t a_stackSize); 
    ~Stack();
    Stack(Stack const& a_source);       //copy constructor
    Stack& operator=(Stack const& a_source); 
	
	//methods
    void push(int x);
    void pushArray(int const *a_array, size_t a_nItems, size_t a_arrSize);
    int pop();
    void popToArray(int *a_array, size_t a_nItems, size_t a_arrSize);
    void empty(); 
    void ensureCapacity(size_t a_capacity); //enlarge capacity if needed
    void drain(Stack &a_source);
    
    int size() const;
    bool isEmpty() const;
    bool isFull() const;
    void dump() const;
    void dumpElements() const;
    size_t capacity() const;
    int top() const;
    
private:
    void axioms() const;
    
    // data member
private:
    size_t m_capacity;
    int *m_elements;
    size_t m_tos;

};

void combine(Stack &a_destination, Stack &a_first, Stack &a_second);

#endif

