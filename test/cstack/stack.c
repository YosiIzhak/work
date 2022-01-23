#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define MAGIC_NUMBER 942199

struct Stack
{
    int*   m_items;
    size_t  m_originalSize; /* original allocated space for items)*/	
    size_t  m_size;      /* actual allocated space for items)*/
    size_t  m_nItems;     	    /* actual number of items */
    size_t  m_magicNumber;
};

Stack* StackCreate (size_t _size)
{
	Stack *stack;
	if (_size == 0)
	{
		return NULL;
	}
	stack = (Stack*) malloc (sizeof(Stack));
	if (stack == NULL) 
	{
        	return NULL;
   	}
	stack->m_items = (int*) malloc(_size * sizeof(int));
	if (stack->m_items == NULL) 
	{
        free(stack);
        return NULL;
   	}
  	stack->m_originalSize = _size;
  	stack->m_nItems = 0;
  	stack->m_size = _size;
  	stack->m_magicNumber = MAGIC_NUMBER;
	return stack;
}

void StackDestroy (Stack* _stack)
{
	if(_stack == NULL || _stack->m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}
		_stack->m_magicNumber = 0;
		free(_stack->m_items);
		free (_stack);
}	
	
ADTErr StackPush (Stack* _stack, int  _item)
{
	int* temp;
	if(_stack ==NULL )
	{
	return ERR_NOT_INITIALIZED;
	}
	if((_stack -> m_nItems) < (_stack -> m_size))
	{
		_stack -> m_items[_stack -> m_nItems] = _item;
		_stack -> m_nItems++;
	}
	return ERR_OK;
}

ADTErr StackPop (Stack* _stack, int* _item)
{
	if(_stack ==NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	*_item =  _stack -> m_items [_stack -> m_nItems - 1];
		_stack -> m_nItems--;
		return ERR_OK;
}

ADTErr StackTop (Stack* _stack, int* _item)
{
	  size_t numOfElements;
	  ADTErr status;
	  if (_stack == NULL)
	  { 
		return ERR_NOT_INITIALIZED;
	  } 
	
	  *_item = _stack->m_items[_stack -> m_nItems - 1];
    return ERR_OK;
}

int StackIsEmpty(Stack* _stack)
{
	if(_stack == NULL)
	{
		return 1;
	}
	if (_stack->m_nItems == 0)
	{ 
		return 1;
	} 
	else
	{
		return 0;
	}
}

void StackPrint (Stack *_stack)
{
	int i;
	if (_stack == NULL)
	  { 
		return;
	  } 
	for (i=0; i< _stack->m_nItems; i++)
	{
    		printf("%d ", _stack->m_items[i]);
	}
	return;
}



