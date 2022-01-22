#include <stdio.h>
#include <stdlib.h>
#include "../../inc/stack.h"
#include "../mu_test.h"
#define TRUE 1
#define FALSE 0

BEGIN_TEST(CreateEmptyStack)

    int stackSize = 4;
    Stack* stack = StackCreate(stackSize);
    ASSERT_NOT_EQUAL(NULL, stack);
    ASSERT_EQUAL(StackIsEmpty(stack), TRUE);

END_TEST

BEGIN_TEST(push)
	int item;
	int stackSize = 4;
    Stack* stack = StackCreate(stackSize);
    StackPush (stack, 2);
    StackPush (stack, 3);
    StackPop (stack, &item);
    ASSERT_EQUAL(3, item);
END_TEST

BEGIN_TEST(empty)
	int item;
	int stackSize = 4;
    Stack* stack = StackCreate(stackSize);
    StackPush (stack, 2);
    StackPush (stack, 3);
    StackPop (stack, &item);
    StackPop (stack, &item);
   ASSERT_EQUAL(StackIsEmpty(stack), TRUE);
END_TEST

BEGIN_TEST(top)
    int item;
    int stackSize = 4;
    Stack* stack = StackCreate(stackSize);
    StackPush (stack, 2);
    StackPush (stack, 3);
    StackTop (stack, &item);
    ASSERT_EQUAL(item, 3);
END_TEST

BEGIN_TEST(DoubleFree)
    int stackSize = 4;
    Stack* stack = StackCreate(stackSize);
    StackDestroy(&stack);
    StackDestroy(&stack);
    ASSERT_PASS();
END_TEST


BEGIN_SUITE(不耻下问 this is a description)
    TEST(CreateEmptyStack)
    TEST(push)
    TEST(empty)
    TEST(top)
    TEST(DoubleFree)
END_SUITE


