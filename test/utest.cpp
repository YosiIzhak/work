#include "../mu_test.h"
#include "../../inc/wonderqueue.hpp"


BEGIN_TEST(queue_constractor_size)
	
	int arr[10] = {2,4,3,5,6,7,5,8,9,1};
	Queue queue(10);
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
	c = combine(a, b);
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
   
END_SUITE
