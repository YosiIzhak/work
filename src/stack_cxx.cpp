#include <cstdio>
#include <cstdlib> //size_t
#include <cassert>
#include <cstring>
#include "stack.hpp"

/*--------------- constructors ---------------*/
Stack::Stack(size_t a_capacity)
: m_capacity(a_capacity)
, m_elements(new int[m_capacity])
, m_tos(0)
{
    axioms();
}

Stack::Stack(int const *a_array, size_t a_arrSize)
: m_capacity(a_arrSize)
, m_elements(new int[a_arrSize])
, m_tos(0)
{
    assert(a_array != NULL);
    pushArray(a_array, a_arrSize, a_arrSize);
}

Stack::Stack(int const *a_array, size_t a_arrSize, size_t a_nItems, size_t a_stackSize)
: m_capacity(a_stackSize)
, m_elements(new int[a_stackSize])
, m_tos(0)
{
    assert(a_array != NULL);
    pushArray(a_array, a_nItems, a_arrSize);
}
/*-------------- de-constructor -------------*/
Stack::~Stack()
{
	delete[] m_elements;
}
/*------- private function --------------------*/
void Stack::axioms() const
{
    assert(m_elements != NULL);
    assert(m_capacity >= 0);
    assert(m_tos >=0 && m_tos <= m_capacity);
}
/*----------------- functions -----------------*/

bool Stack::isEmpty() const
{
    axioms();
    return m_tos == 0;
}
/*---------------------------------------------*/
bool Stack::isFull() const
{
    axioms();
    return m_tos == m_capacity;
}
/*---------------------------------------------*/
int Stack::size() const
{
    axioms();
    return m_tos;
}
/*---------------------------------------------*/
size_t Stack::capacity() const
{
    axioms();
    return m_capacity;
}
/*---------------------------------------------*/
int Stack::pop()
{
    assert(!isEmpty());
    int r = m_elements[--m_tos];
	axioms();   
    return r;
}
/*---------------------------------------------*/
void Stack::push(int value)
{
    assert(!isFull());
    m_elements[m_tos++] = value;
    axioms();   
}
/*---------------------------------------------*/
void Stack::empty() 
{
	m_tos = 0;
	axioms();
}
/*---------------------------------------------*/
int Stack::top() const
{
    assert(!isEmpty());   
	axioms();   
    return m_elements[m_tos-1];
}
/*---------------------------------------------*/
void Stack::dumpElements() const
{
    for (size_t i = 0; i < m_tos; i++)
    {
        printf("%d, ", m_elements[i]);
    }
}
/*---------------------------------------------*/
void Stack::dump() const
{
    printf("tos: %ld, cap: %ld\n", m_tos, m_capacity);
    dumpElements();
    printf("\n");
}
/*---------------------------------------------*/
void Stack::pushArray(int const *a_array, size_t a_nItems, size_t a_arrSize)
{
    assert(a_array != NULL);  
    assert(a_nItems <= a_arrSize);
    assert(a_nItems <= m_capacity);

    //memcpy(); change later
    for(size_t i = 0; i < a_nItems; i++)
    {
        push(a_array[i]);
    }
    axioms();
}
/*---------------------------------------------*/   
void Stack::popToArray(int *a_array, size_t a_nItems, size_t a_arrSize)
{
    size_t i = 0; 

    assert(a_array != NULL);
    assert(a_nItems <= m_tos);

    while(i < a_nItems && i < a_arrSize)
    {
        a_array[i] = pop();
        i++;
    }
    axioms();
}
/*---------------------------------------------*/
void Stack::ensureCapacity(size_t a_capacity)
{
    if(capacity() >= a_capacity){return;} 
    int *newArray = new int[a_capacity];
    memcpy(newArray, m_elements, sizeof(m_elements[0]) * m_tos);
    int *oldArray = m_elements; 
    m_elements = newArray;
    m_capacity = a_capacity;
    delete[] oldArray;
    axioms(); 
}
/*---------------------------------------------*/
void Stack::drain(Stack &a_source)
{
    ensureCapacity(a_source.capacity());
    
    while(a_source.m_tos != 0)
    {
        push(a_source.pop());
    }
    axioms(); 
}
/*---------------------------------------------*/
void combine(Stack &a_destination, Stack &a_first, Stack &a_second) 
{
    size_t totalCapacity = a_first.size() + a_second.size();

    a_destination.ensureCapacity(totalCapacity);

    a_destination.drain(a_first);
    a_destination.drain(a_second);
}




