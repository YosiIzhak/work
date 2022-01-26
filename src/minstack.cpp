#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <string.h>

#include "minstack.hpp"

/******Constructor*******/

minStack::minStack(size_t a_capacity)
:m_size(0)
,m_minSize(0)
,m_capacity(a_capacity)
{
    assert(a_capacity >= 0);
	m_stack = new Stack(a_capacity);
    m_minStack = new Stack(a_capacity);
    axioms();
}
/******destroy*******/

minStack::~minStack()
{
  delete m_stack;
  delete m_minStack;
}

/******axioms*******/

void minStack::axioms() const
{
    assert(m_size >= 0 && m_size <= m_capacity);
    assert(m_capacity >= 0 && m_capacity <= 100000000);
}

/******isEmpty*******/

bool minStack::isEmpty() const
{
    return m_size == 0;
}

/*******isFull*******/

bool minStack::isFull() const
{
    return m_size == m_capacity;
}

/*******size*******/

size_t minStack::size() const
{
    return m_size;
}
/*******capacity*******/

size_t minStack::capacity() const
{
    return m_capacity;
}
/*******pop*******/


int minStack::pop()
{
    assert(!m_stack->isEmpty());
    int result = m_stack->top();
    m_size--;
    if(result == m_minStack->top())
    {
    	m_minSize--;
    }
    axioms();
    return result;
}

/*******push*******/
void minStack::push(int a_item)
{
    assert(!m_stack->isFull());
    m_stack->push(a_item);
    m_size++;
    if (m_minStack->isEmpty())
    {
    	m_minStack->push(a_item);
    	m_minSize++;
    }
    else if(a_item <= m_minStack->top())
    {
    	m_minStack->push(a_item);
    	m_minSize++;
    }
   
     axioms();
}

/*******dumpElements*******/

void minStack::dumpElements() const
{
   m_stack->dumpElements();
     axioms();
}

/*******dump*******/

void minStack::dump() const
{
    printf("size: %ld,  cap: %ld\n", m_size, m_capacity);
    dumpElements();
    printf("\n");
     axioms();
}


/*******top*******/
int minStack::top() const
{
   return m_stack->top();
}
/*******min*******/
int minStack::min() const
{
	return m_minStack->top();
}











