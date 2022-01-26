#include "mu_test.h"
#include "minstack.hpp"


BEGIN_TEST(minstack_constractor)
	
	minStack minStack(10);
	ASSERT_THAT(minStack.capacity() == 10);
	ASSERT_THAT(minStack.size() == 0);
	minStack.dump();
END_TEST

BEGIN_TEST(minstack_push)
	
	minStack minStack(10);
	ASSERT_THAT(minStack.capacity() == 10);
	ASSERT_THAT(minStack.size() == 0);
	minStack.push(8);
	minStack.push(4);
	minStack.push(5);
	ASSERT_THAT(minStack.size() == 3);
	minStack.dump();
END_TEST

BEGIN_TEST(minstack_push_min)
	
	minStack minStack(10);
	ASSERT_THAT(minStack.capacity() == 10);
	ASSERT_THAT(minStack.size() == 0);
	minStack.push(8);
	minStack.push(4);
	minStack.push(5);
	ASSERT_THAT(minStack.size() == 3);
	ASSERT_THAT(minStack.min() == 4);
	minStack.dump();
END_TEST

BEGIN_TEST(minstack_push_six)
	
	minStack minStack(10);
	ASSERT_THAT(minStack.capacity() == 10);
	ASSERT_THAT(minStack.size() == 0);
	minStack.push(8);
	minStack.push(4);
	minStack.push(5);
	minStack.push(1);
	minStack.push(3);
	minStack.push(7);
	ASSERT_THAT(minStack.size() == 6);
	ASSERT_THAT(minStack.min() == 1);
	minStack.dump();
END_TEST

BEGIN_SUITE(不耻下问 this is a description)
 	TEST(minstack_constractor)
 	TEST(minstack_push)
 	TEST(minstack_push_min)
 	TEST(minstack_push_six)
END_SUITE
