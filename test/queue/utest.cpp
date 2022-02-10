#include "mu_test.h"
#include "queue.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>

/*------------------------------------*/
BEGIN_TEST(new_queue)
    using Cpp::Queue;
    Queue<int> a(10);
	ASSERT_EQUAL(a.size(),0);

END_TEST
BEGIN_TEST(enqueue_items)
 using Cpp::Queue;
    Queue<int> a(10);
	a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    ASSERT_EQUAL(a.size(),4);

END_TEST

BEGIN_TEST(dequeue_items)
 using Cpp::Queue;
    Queue<int> a(10);
	a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    a.dequeue();
    ASSERT_EQUAL(a.size(),3);

END_TEST

class Dog{

public:

    void walk() const { std::cout << "walk the dog\n"; }

};
BEGIN_TEST(dog_items)
using Cpp::Queue;
    Queue<Dog> a(10);
    Dog d;
    Dog d1;
	a.enqueue(d);
    a.enqueue(d1);
    
    a.dequeue();
    ASSERT_EQUAL(a.size(),1);

END_TEST

BEGIN_TEST(queue_queue)

	using namespace Cpp;

	Queue< Queue<int> > q(2);

	ASSERT_EQUAL(q.size(), 0);
	ASSERT_EQUAL(q.isEmpty(), true);
	ASSERT_EQUAL(q.isFull(), false);

	Queue<int> first;
	first.enqueue(1);
	first.enqueue(2);
	first.enqueue(3);
	q.enqueue(first);
	ASSERT_EQUAL(q.size(), 1);

	Queue<int> second;
	second.enqueue(4);
	second.enqueue(5);
	q.enqueue(second);
	ASSERT_EQUAL(q.size(), 2);

	ASSERT_EQUAL(q.isEmpty(), false);
	ASSERT_EQUAL(q.isFull(), true);

	Queue< Queue<int> > copy;
	copy = q;
	ASSERT_EQUAL(copy.size(), 2);

	Queue<int> temp = q.dequeue();
	ASSERT_EQUAL(temp.size(), first.size());

	temp = q.dequeue();
	ASSERT_EQUAL(temp.size(), second.size());

	ASSERT_EQUAL(q.isEmpty(), true);
	ASSERT_EQUAL(q.isFull(), false);

	copy.clear();
	ASSERT_EQUAL(copy.size(), 0);
	ASSERT_EQUAL(copy.isEmpty(), true);
	ASSERT_EQUAL(copy.isFull(), false);

END_TEST
BEGIN_SUITE(option)
	
	TEST(new_queue)
    TEST(enqueue_items)
    TEST(dequeue_items)
    TEST(dog_items)
    TEST(queue_queue)
END_SUITE
