#include <cstdio>
#include <cassert>
#include <cstdlib>

#include "../inc/stack.hpp"// initial value of m_tos ==0 && m_capacity 
Stack::Stack(int size)
{
    m_tos = 0;
    m_capacity = size;
    m_elements = (int*) malloc(size * sizeof(int));
    assert(m_elements != NULL);
}

bool Stack::isEmpty()
{
    return m_tos == 0;
}
bool Stack::isFull()
{
    return m_tos == m_capacity;
}
int Stack::size()
{
    return m_tos;
}
int Stack::pop()
{
    assert(!isEmpty());
    return m_elements[--m_tos];
}void Stack::push(int value)
{
    assert(!isFull());
    m_elements[m_tos++] = value;
}
void Stack::dumpElements()
{
    for (int i = 0; i < m_tos; i++)
    {
        printf("%d ", m_elements[i]);
    }
}
void Stack::dump()
{
    printf("tos: %d,  cap: %d\n", m_tos, m_capacity);
    dumpElements();
    printf("\n");
}
