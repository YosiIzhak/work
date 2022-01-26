#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <string.h>
#include "wonderqueue.hpp"

/******Constructor*******/

WonderQueue::WonderQueue(size_t a_capacity)
:m_capacity(a_capacity)
,m_size(0)
{
   m_firstStack = new Stack(a_capacity);
   m_secondStack = new Stack(a_capacity);
    axioms();
}
/******destroy*******/

WonderQueue::~WonderQueue()
{
  delete m_firstStack;
  delete m_secondStack;
}

/******axioms*******/

void WonderQueue::axioms() const
{
   /* assert(m_tos >= 0 && m_tos <= m_capacity);*/
    assert(m_size >= 0 && m_size <= 100000000);
}
/******enqueue*******/
void WonderQueue::enqueue(int a_item)
{
	m_firstStack->push(a_item);
	m_size++;
}
/******dequeue*******/
int WonderQueue::dequeue()
{
	int item;
	assert(m_secondStack->size() == 0);
	m_secondStack->drain(*m_firstStack);
	item = m_secondStack->pop();
	m_firstStack->drain(*m_secondStack);
	m_size--;
	return item;
}
 
/******isEmpty*******/

bool WonderQueue::isEmpty() const
{
    return m_size == 0;
}

/*******isFull*******/

bool WonderQueue::isFull() const
{
    return m_size == m_capacity;
}

/*******size*******/

size_t WonderQueue::size() const
{
    return m_size;
}
/*******capacity*******/

size_t WonderQueue::capacity() const
{
    return m_capacity;
}
/*******dumpElements*******/

void WonderQueue::dumpElements() const
{
    m_firstStack->dumpElements();
	axioms();
}

/*******dump*******/
void WonderQueue::dump() const
{
    printf("size: %ld,  cap: %ld\n", m_size, m_capacity);
    dumpElements();
    printf("\n");
     axioms();
}






