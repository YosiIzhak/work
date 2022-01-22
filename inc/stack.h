#ifndef __STACK_H__
#define __STACK_H__

typedef enum 
{
    /* General ADT Errors */
    ERR_OK                            =0,
    ERR_GENERAL,
    ERR_NOT_INITIALIZED,
    ERR_ALLOCATION_FAILED,
    ERR_REALLOCATION_FAILED,
    ERR_UNDERFLOW,
    ERR_OVERFLOW,
    ERR_WRONG_INDEX,
    MAGIC_NUMBER_STACK,
    NO_BALANCE,
		    /* Vector Errors */
    /* Stack  Errors */
    ERR_STACK_BBBBB = 30
    /* LinkedList  Errors */
    /* Bit Vector*/
} ADTErr;

typedef struct Stack Stack;

Stack*  StackCreate (size_t _size);
void    StackDestroy(Stack** _stack);
ADTErr  StackPush (Stack* _stack, int  _item);
ADTErr  StackPop (Stack* _stack, int* _item);
ADTErr  StackTop (Stack* _stack, int* _item);
int     StackIsEmpty(Stack* _stack);

/*  Unit-Test functions  */
void    StackPrint   (Stack *_stack);




#endif
