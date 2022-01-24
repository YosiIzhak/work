#include <cstdio>
#include <cassert>
#include <cstdlib>

#include "../inc/stack.hpp"
Stack::Stack(size_t size)
{
    m_tos = 0;
    m_capacity = size;
    m_elements = (int*) malloc(size * sizeof(int));
    assert(m_elements != NULL);
}

bool Stack::isEmpty() const
{
    return m_tos == 0;
}
bool Stack::isFull() const
{
    return m_tos == m_capacity;
}
size_t Stack::size() const
{
    return m_tos;
}
int Stack::pop()
{
    assert(!isEmpty());
    return m_elements[--m_tos];
}
void Stack::push(int value)
{
    assert(!isFull());
    m_elements[m_tos++] = value;
}
void Stack::dumpElements() const
{
    for (size_t i = 0; i < m_tos; i++)
    {
        printf("%d ", m_elements[i]);
    }
}
void Stack::dump() const
{
    printf("tos: %ld,  cap: %ld\n", m_tos, m_capacity);
    dumpElements();
    printf("\n");
}
void Stack::empty()
{
	m_tos = 0;
}

void Stack::axioms() const
{
	assert(m_tos < m_capacity);
}
