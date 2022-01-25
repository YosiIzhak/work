#include <cstdio>
#include <cassert>
#include <cstdlib>

#include "../inc/stack.hpp"
const size_t arraySize  = 100;
/******Constructor*******/

Stack::Stack(size_t a_capacity)
:m_tos(0)
,m_capacity(a_capacity)
{
    assert(a_capacity >= 0);
	m_elements = new int [a_capacity];
    axioms();
}

Stack::Stack(int a_arr[], size_t a_size)
:m_tos(0)
{
	/*assert(a_size <= arraySize);*/
	
	m_capacity = a_size;
	
	m_elements = new int [m_capacity];
	for(size_t i = 0; i < a_size; i++)
	{
		/*m_elements[i] = a_arr[i];*/
		
		push(a_arr[i]);
		
	}
    axioms();
}
Stack::Stack(int a_arr[], size_t a_fromArr, size_t a_size)
:m_tos(0)
{
	assert(a_fromArr <= arraySize);
	
	m_capacity = a_size;
	assert(m_capacity >= 0);
	m_elements = new int [m_capacity];
	for(size_t i = 0; i < a_fromArr; i++)
	{
		/*m_elements[i] = a_arr[i];*/
		push(a_arr[i]);
	}
    axioms();
}
/******destroy*******/

Stack::~Stack()
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

/*******pop*******/
int* Stack::pop(int a_arr[], size_t a_arrSize)
{
	 assert(!isEmpty());
	  for (size_t i = 0; i < a_arrSize; i++)
	  {
	  		a_arr[i] = m_elements[m_tos--];
     		axioms();
	 		if (m_tos == 0)
	 		{
	 			break;
	 		}
	  }
	  return a_arr;
} 

int Stack::pop()
{
    assert(!isEmpty());
    int result = m_elements[--m_tos];
    axioms();
    return result;
}

/*******push*******/
void Stack::push(int a_arr[], size_t a_arrSize)
{
	
	 assert(!isFull());
	 for (size_t i = 0; i < a_arrSize; i++)
	 {
	  	m_elements[m_tos++] = a_arr[i];
     	axioms();
	 	if (m_tos == m_capacity)
	 	{
	 		break;
	 	}
	 }
}

void Stack::push(int a_item)
{
    assert(!isFull());
    m_elements[m_tos++] = a_item;
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

/*******empty*******/

void Stack::empty()
{
   m_tos = 0;
   axioms();
}
/*******mergeTwoStacks*******/
Stack mergeTwoStacks(Stack a_first, Stack a_second)
{
	size_t firstSize = a_first.size();
	size_t secondSize = a_second.size();
	int* carr;
	int* firstArr = new int[firstSize];
	int* secondArr = new int[secondSize];
	size_t size = a_first.size() + a_second.size();
	
	Stack newStack(size);
	
	carr = a_first.pop(firstArr, a_first.size());
	for (size_t i = 0; i < a_first.size(); i++)
    {
       printf("%d\n**** ", firstArr[i]);
       printf("%d\n**** ", carr[i]);
    }
	
	a_second.pop(secondArr, a_second.size());
	
	newStack.push(firstArr, firstSize);
	newStack.push(secondArr, secondSize);
	return newStack;
}

Stack::Stack(const Stack &a_stack)
{
    m_capacity = a_stack.m_capacity;
    m_tos = a_stack.m_tos;
    m_elements = new int[m_capacity];
    for (size_t i = 0 ; i< m_tos; i++)
    {
        m_elements[i] = a_stack.m_elements[i];
    }
}











