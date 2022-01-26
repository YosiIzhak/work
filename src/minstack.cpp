#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <string.h>

#include "minstack.hpp"
const size_t arraySize  = 100;
/******Constructor*******/

minStack::minStack(size_t a_capacity)
:m_tos(0)
,m_capacity(a_capacity)
{
    assert(a_capacity >= 0);
	m_elements = new int [a_capacity];
    axioms();
}
/******destroy*******/

minStack::~minStack()
{
  delete[]m_elements;
}

/******axioms*******/

void Stack::axioms() const
{
    assert(m_tos >= 0 && m_tos <= m_capacity);
    assert(m_capacity >= 0 && m_capacity <= 100000000);
    assert(m_elements != 0);
}

/******isEmpty*******/

bool Stack::isEmpty() const
{
    return m_tos == 0;
}

/*******isFull*******/

bool Stack::isFull() const
{
    return m_tos == m_capacity;
}

/*******size*******/

size_t Stack::size() const
{
    return m_tos;
}
/*******capacity*******/

size_t Stack::capacity() const
{
    return m_capacity;
}
/*******pop*******/


int Stack::pop()
{
    assert(!isEmpty());
    int result = m_elements[--m_tos];
    axioms();
    return result;
}

/*******push*******/
void Stack::push(int a_item)
{
    assert(!isFull());
    m_elements[m_tos++] = a_item;
    if (a_item <= m_stack->m_stack.top())
    {
    	m_stack.push(a_item);
    }
   
     axioms();
}

/*******dumpElements*******/

void Stack::dumpElements() const
{
    for (size_t i = 0; i < m_tos; i++)
    {
        printf("%d ", m_elements[i]);
    }
     axioms();
}

/*******dump*******/

void Stack::dump() const
{
    printf("tos: %ld,  cap: %ld\n", m_tos, m_capacity);
    dumpElements();
    printf("\n");
     axioms();
}


/*******top*******/
int Stack::top() const
{
   return m_elements[m_tos];
}
/*******min*******/
int Stack::min() const












