#include "../mu_test.h"
#include "../../inc/stack.hpp"

BEGIN_TEST(new_stack_is_empty)
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


BEGIN_SUITE(不耻下问 this is a description)
    TEST(new_stack_is_empty)
    TEST(stack_is_full)
    TEST(stack_size_standard)
    TEST(stack_push_pop)
    
END_SUITE
