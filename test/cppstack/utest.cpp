#include "mu_test.h"
#include "stack.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>

/*------------------------------------*/
BEGIN_TEST(push_items)
    Stack stack;

    ASSERT_EQUAL(stack.size(), 0);
    stack.push(4);
    stack.push(9);
    stack.push(42);
    ASSERT_EQUAL(stack.size(), 3);
    stack.dump();
END_TEST

/*------------------------------------*/
BEGIN_TEST(pop_items)
    Stack stack;

    stack.push(4);
    stack.push(9);
    stack.push(42);
    ASSERT_EQUAL(stack.size(), 3);
    stack.pop();
    stack.pop();
    stack.pop();
    ASSERT_EQUAL(stack.size(), 0);
    stack.dump();
END_TEST

/*------------------------------------*/
BEGIN_TEST(empty_stack)
    Stack stack;

    stack.push(4);
    stack.push(9);
    stack.push(42);
    //stack.dump();
	stack.empty();
    ASSERT_EQUAL(stack.size(), 0);
    ASSERT_THAT(stack.isEmpty());
    stack.dump();
END_TEST

/*------------------------------------*/
BEGIN_TEST(is_empty)
    Stack stack;
    bool r = stack.isEmpty();
    ASSERT_THAT(r);
    ASSERT_THAT(stack.isEmpty());
    ASSERT_EQUAL(stack.size(), 0);
    stack.push(4);
    stack.push(9);
    stack.push(42);
    ASSERT_EQUAL(stack.isEmpty(), false);
    stack.dump();
END_TEST

/*------------------------------------*/
BEGIN_TEST(is_stack_full)
    Stack stack(3);

    stack.push(4);
    stack.push(9);
    ASSERT_EQUAL(stack.isFull(), false);
    stack.push(42);

    ASSERT_EQUAL(stack.isFull(), true);
    stack.dump();
END_TEST

/*------------------------------------*/
BEGIN_TEST(stack_destruction)
    Stack stack(80);

    stack.push(4);
    stack.push(9);

	ASSERT_PASS();
END_TEST

/*------------------------------------*/
BEGIN_TEST(push_array_to_stack)
    Stack s1, s2;
    int array[10];
    
    for(int i = 0; i < 10; i++)
    {
        array[i] = i;
    }
    
    s1.pushArray(array, 10, 10);
    ASSERT_EQUAL(s1.size(), 10);
    s1.dump();

    s2.pushArray(array, 7, 10);
    ASSERT_EQUAL(s2.size(), 7);
    s2.dump();

END_TEST

/*------------------------------------*/
BEGIN_TEST(pop_stack_into_array)
    int array[] = {1,2,3,4,5,6,7,8,9,10}; 
    int flippedArr[] = {10,9,8,7,6,5,4,3,2,1};
    int popArr[20];        
    Stack s1(array,10,10,10);
    Stack flippedStack(flippedArr,10,10,10);

    s1.popToArray(popArr, 10, 20);
    ASSERT_EQUAL(s1.size(), 0);
    s1.dump();
    ASSERT_EQUAL(memcmp(popArr, flippedArr, sizeof(flippedArr)), 0);

END_TEST
/*------------------------------------*/

BEGIN_TEST(combine_two_stacks)
    int array[10], array2[10];
    Stack comb(15);

    for(int i = 0; i < 10; i++)
    {
        array[i] = i;
        array2[i] = i * (-1);
    }
    
    Stack s1(array,10);
    Stack s2(array2,10);

    combine(comb ,s1, s2);

    ASSERT_EQUAL(comb.size(), 20);
    ASSERT_THAT(comb.isFull());
    ASSERT_EQUAL(s1.size(), 0);
    ASSERT_EQUAL(s2.size(), 0);
    comb.dump();

END_TEST

/*------------------------------------*/
BEGIN_TEST(combine_with_empty_stack)
    int array[] = {1,2,3,4,5,6,7,8,9,10}; 
    int array2[] = {99}; 
    Stack comb(5);
    
    Stack s1(array,10);
    Stack s2(array2,1);

    combine(comb ,s1, s2);

    ASSERT_EQUAL(comb.size(), 11);
    ASSERT_THAT(comb.isFull());
    ASSERT_EQUAL(s1.size(), 0);
    ASSERT_EQUAL(s2.size(), 0);
    comb.dump();

END_TEST

/*------------------------------------*/
BEGIN_TEST(check_copy_constructor)
    int array[] = {1,2,3,4,5,6,7,8,9,10}; 

    Stack s1(array,10);
    Stack s2(s1);

    //ASSERT_EQUAL(memcmp(&s2, &s1, sizeof(s2)), 0);  //check why doesn't work

    s1.dump();
    s2.dump();
    ASSERT_EQUAL(s1.size(), s2.size());
    ASSERT_EQUAL(s1.capacity(), s2.capacity());
    
    for(int i = 1; i <= 10; i++)
    {
        ASSERT_EQUAL(s1.pop(), s2.pop());
    }

END_TEST

/*------------------------------------*/
BEGIN_TEST(check_copy_assignment_operator)
    int array[] = {1,2,3,4,5,6,7,8,9,10}; 

    Stack s1(array,10);
    Stack s2(10);

    s2 = s1;
    s1.dump();
    s2.dump();
    ASSERT_EQUAL(s1.size(), s2.size());
    ASSERT_EQUAL(s1.capacity(), s2.capacity());
    
    for(int i = 1; i <= 10; i++)
    {
        ASSERT_EQUAL(s1.pop(), s2.pop());
    }

END_TEST

/*####################################*/
BEGIN_SUITE(ה¸ט€»ה¸‹י—® this is a description)
	TEST(push_items)
	TEST(pop_items)
    TEST(is_empty)
    TEST(empty_stack)
    TEST(is_stack_full)
    TEST(stack_destruction)
    TEST(push_array_to_stack)
    TEST(pop_stack_into_array)
    TEST(combine_two_stacks)
    TEST(combine_with_empty_stack)
    TEST(check_copy_constructor)
    TEST(check_copy_assignment_operator)

END_SUITE



