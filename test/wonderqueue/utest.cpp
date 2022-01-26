#include "mu_test.h"
#include "wonderqueue.hpp"


BEGIN_TEST(WonderQueue_constractor_cap)
	
	WonderQueue wonderQueue(10);
	ASSERT_THAT(wonderQueue.capacity() == 10);
	wonderQueue.dump();
END_TEST

BEGIN_TEST(WonderQueue_constractor_size)
	WonderQueue wonderQueue(10);
	ASSERT_THAT(wonderQueue.capacity() == 10);
	wonderQueue.enqueue(2);
	wonderQueue.enqueue(3);
	wonderQueue.enqueue(4);
	ASSERT_THAT(wonderQueue.size() == 3);
	wonderQueue.dump();
	
END_TEST

BEGIN_TEST(WonderQueue_constractor_deq)
	WonderQueue wonderQueue(10);
	ASSERT_THAT(wonderQueue.capacity() == 10);
	wonderQueue.enqueue(2);
	wonderQueue.enqueue(3);
	wonderQueue.enqueue(4);
	ASSERT_THAT(wonderQueue.size() == 3);
	wonderQueue.dequeue();
	ASSERT_THAT(wonderQueue.size() == 2);
	wonderQueue.dump();
	
END_TEST


BEGIN_SUITE(不耻下问 this is a description)
 	TEST(WonderQueue_constractor_cap)
 	TEST(WonderQueue_constractor_size)
   	TEST(WonderQueue_constractor_deq)
END_SUITE
