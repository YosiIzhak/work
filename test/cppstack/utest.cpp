#include "../mu_test.h"
#include "../../inc/stack.hpp"

/*BEGIN_TEST(new_stack_is_empty)
    Stack stack(5); 
    bool r = stack.isEmpty();
    ASSERT_THAT(r);  
    ASSERT_THAT(stack.isEmpty());
    ASSERT_EQUAL(stack.size(), 0);
    stack.push(4);
    stack.push(9);
    stack.push(42);    
    stack.dump();
END_TEST

BEGIN_TEST(stack_is_full)
	Stack stack(5);
	ASSERT_THAT(stack.isEmpty());
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);	
	ASSERT_THAT(stack.isFull());
    stack.dump();
END_TEST

BEGIN_TEST(stack_size_standard)
	Stack stack(5);
	ASSERT_THAT(stack.isEmpty());
	stack.push(42);
	ASSERT_THAT(stack.size() == 1);
	stack.dump();
END_TEST

BEGIN_TEST(stack_push_pop)
	Stack stack(4);
	ASSERT_THAT(stack.isEmpty());
	stack.push(42);
	int num = stack.pop();
	ASSERT_THAT(num == 42);
	stack.dump();
END_TEST

BEGIN_TEST(stack_empty)
	Stack stack(3);
	ASSERT_THAT(stack.isEmpty());
	stack.push(4);
	stack.push(9);
	stack.push(42);
	ASSERT_THAT(stack.isFull());
	stack.empty();
	ASSERT_THAT(stack.isEmpty());
	stack.push(2);
	stack.push(9);
	stack.push(42);
    stack.dump();
END_TEST

BEGIN_TEST(stack_fill_empty)
	size_t n= 10;
	Stack stack(n);
	ASSERT_EQUAL(stack.isEmpty(), true);
	for(size_t i=0; i<n; i++)
	{
		ASSERT_EQUAL(stack.isFull(), false);
		ASSERT_EQUAL(stack.size(), i);
		stack.push((int)i);
		ASSERT_EQUAL(stack.isEmpty(), false);
	}
	ASSERT_EQUAL(stack.isFull(), true);
	for(size_t i=n-1; i>=0; --i)
	{
		if(i>n)
		{
			break;
		}
		ASSERT_EQUAL(stack.isEmpty(), false);
		int x = stack.pop();
		ASSERT_EQUAL(x, (int)i);
		ASSERT_EQUAL(stack.isFull(), false);
	}
	ASSERT_EQUAL(stack.isEmpty(), true);
END_TEST*/
BEGIN_TEST(stack_constractor_size)
	
	int arr[10] = {2,4,3,5,6,7,5,8,9,1};
	Stack stack(arr, 10);
	ASSERT_THAT(stack.size() == 10);
	stack.dump();
END_TEST

BEGIN_TEST(stack_constractor_size_copy)
	int arr[100];
	for(size_t i =0; i< 100; i++)
	{
		arr[i] = i;
	}
	Stack stack(arr, 32, 128);
	ASSERT_THAT(stack.size() == 32);
	/*stack.dump();*/
END_TEST

BEGIN_TEST(push_array)
	int arr[10] = {2,4,3,5,6,7,5,8,9,1};
	Stack stack(15);
	ASSERT_THAT(stack.isEmpty());
	stack.push(arr, 10);
	stack.dump();
END_TEST

BEGIN_TEST(push_array_small_size)
	int arr[10] = {2,4,3,5,6,7,5,8,9,1};
	Stack stack(7);
	ASSERT_THAT(stack.isEmpty());
	stack.push(arr, 10);
	stack.dump();
END_TEST

BEGIN_TEST(pop_to_array)
	int arr[10] = {2,4,3,5,6,7,5,8,9,1};
	int arrPop[10];
	Stack stack(17);
	ASSERT_THAT(stack.isEmpty());
	stack.push(arr, 10);
	stack.pop(arrPop, 10);
	stack.dump();
END_TEST

BEGIN_TEST(pop_to_array_small)
	int arr[10] = {2,4,3,5,6,7,5,8,9,1};
	int arrPop[10];
	Stack stack(5);
	ASSERT_THAT(stack.isEmpty());
	stack.push(arr, 10);
	ASSERT_THAT(stack.size() == 5);
	stack.pop(arrPop, 10);
	stack.dump();
END_TEST

BEGIN_TEST(merge_two_stacks)
	int arr[5] = {1,2,3,4,5};
	Stack a(5);
	ASSERT_THAT(a.isEmpty());
	a.push(arr, 5);
	
	ASSERT_THAT(a.size() == 5);
	Stack b(5);
	ASSERT_THAT(b.isEmpty());
	b.push(arr, 5);
	
	ASSERT_THAT(b.size() == 5);
	Stack c(10);
	c = mergeTwoStacks(a, b);
	ASSERT_THAT(c.size() == 10);
	c.dump();
	
END_TEST

BEGIN_SUITE(不耻下问 this is a description)
 	/*TEST(stack_constractor_size)
 	TEST(stack_constractor_size_copy)
 	TEST(push_array)
 	TEST(push_array_small_size)
 	TEST(pop_to_array)
 	TEST(pop_to_array_small)*/
 	 TEST(merge_two_stacks)
   /*TEST(new_stack_is_empty)
    TEST(stack_is_full)
    TEST(stack_size_standard)
    TEST(stack_push_pop)
    TEST(stack_empty)
    TEST(stack_fill_empty)
   */ 
END_SUITE
