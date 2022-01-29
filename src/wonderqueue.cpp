#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <string.h>
#include "wonderqueue.hpp"

WonderQueue::WonderQueue(size_t a_capacity)
:m_firstStack(a_capacity)
,m_secondStack(a_capacity)
,m_capacity(a_capacity)
,m_size(0)
{
    axioms();
}

void WonderQueue::axioms() const
{
      assert(m_size >= 0 && m_size <= 100000000);
}

void WonderQueue::enqueue(int a_item)
{
	assert(m_size <= m_capacity *2);
	if (m_firstStack.isFull() && m_secondStack.isEmpty())
	{
		m_secondStack.drain(m_firstStack);
		m_firstStack.push(a_item);
		m_size++;
	}
	else if (!m_firstStack.isFull())
	{
		m_firstStack.push(a_item);
		m_size++;
	}
	else
	{
		assert(!m_firstStack.isFull());	
	}
	
}

int WonderQueue::dequeue()
{
	int item;
	if (!m_secondStack.isEmpty())
	{	
		item = m_secondStack.pop();
		m_size--;
	}
	else if (m_secondStack.isEmpty())
	{
		assert(m_secondStack.size() == 0);
		assert(m_firstStack.size() != 0);
		m_secondStack.drain(m_firstStack);
		item = m_secondStack.pop();
		m_size--;
	}
	return item;
}
 
bool WonderQueue::isEmpty() const
{
    return m_size == 0;
}

bool WonderQueue::isFull() const
{
    return m_size == m_capacity;
}

size_t WonderQueue::size() const
{
    return m_size;
}

size_t WonderQueue::capacity() const
{
    return m_capacity;
}

void WonderQueue::dumpElements() const
{
    m_firstStack.dumpElements();
	axioms();
}

void WonderQueue::dump() const
{
    printf("size: %ld,  cap: %ld\n", m_size, m_capacity);
    dumpElements();
    printf("\n");
     axioms();
}






