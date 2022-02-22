#include "mu_test.h"
#include "single_list.hpp"
#include <algorithm>
#include <list>
#include <iostream>
BEGIN_TEST(empty_list)

	LinkedList list;
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_EQUAL(list.isEmpty(), true);

	int r = list.first();
	r = list.last();
	ASSERT_EQUAL(r, 0);

END_TEST

BEGIN_TEST(add_and_remove)

	LinkedList list;
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_EQUAL(list.isEmpty(), true);

	for (int i = 1; i < 11; i++)
	{
		list.add(i);
	}
	ASSERT_EQUAL(list.size(), 10);
	ASSERT_EQUAL(list.isEmpty(), false);

	for (int i = 1; i < 11; i++)
	{
		list.remove();
	}
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_EQUAL(list.isEmpty(), true);

END_TEST

BEGIN_TEST(all_function)

	LinkedList list;
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_EQUAL(list.isEmpty(), true);

	Iterator it;
	it = list.begin();
	ASSERT_EQUAL(it.data(), 0);
	it = list.end();
	ASSERT_EQUAL(it.data(), 0);
	ASSERT_EQUAL(it.equal(list.begin()), true);
	ASSERT_EQUAL(it.notEqual(list.begin()), false);

	for (int i = 1; i < 11; i++)
	{
		list.add(i);
	}
	ASSERT_EQUAL(list.size(), 10);
	ASSERT_EQUAL(list.isEmpty(), false);
	ASSERT_EQUAL(list.first(), 10);
	ASSERT_EQUAL(list.last(), 1);

	it = list.begin();
	ASSERT_EQUAL(it.data(), 10);
	it = it.next();
	ASSERT_EQUAL(it.data(), 9);
	it = list.end();
	ASSERT_EQUAL(it.data(), 0);
	ASSERT_EQUAL(it.equal(list.begin()), false);
	ASSERT_EQUAL(it.notEqual(list.begin()), true);

	it = list.begin();
	int r;
	for (int i = 10; i > 0; i--)
	{
		r = it.data();
		ASSERT_EQUAL(r, i);
		it = it.next();
	}

	for (int i = 1; i < 11; i++)
	{
		list.remove();
	}
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_EQUAL(list.isEmpty(), true);

	it = list.end();
	ASSERT_EQUAL(it.data(), 0);

END_TEST

void addOne(LinkedList a_list)
{
	a_list.add(1);
}

BEGIN_TEST(test_cctor)

	LinkedList list;
	ASSERT_THAT(list.isEmpty());
	addOne(list);
	ASSERT_EQUAL(list.size(), 0);

END_TEST

BEGIN_TEST(test_operator_equal)

	LinkedList a;
	LinkedList b;

	for (size_t i = 1; i < 6; i++)
	{
		b.add(i);
	}

	a = b;
	ASSERT_EQUAL(b.size(), 5);
	ASSERT_EQUAL(a.size(), 5);

END_TEST

BEGIN_TEST(test_find)

	LinkedList a;
	for (size_t i = 1; i < 6; i++)
	{
		a.add(i);
	}

	ASSERT_THAT(a.contains(5));
	ASSERT_THAT(!a.contains(15));

END_TEST

BEGIN_TEST(test_united)

	LinkedList a;
	LinkedList b;
    
	for (size_t i = 1; i < 6; i++)
	{
		a.add(i);
        //a.print();
	}
	for (size_t i = 3; i < 7; i++)
	{
		b.add(i);
       // b.print();
	}
    LinkedList c;
	size_t res = intersect(a, b, c);
    //c.print();
	ASSERT_EQUAL(res, 3);
    	
END_TEST

BEGIN_TEST(iterator_add)

	LinkedList a;
	Iterator it;
	for (size_t i = 1; i < 6; i++)
	{
		a.add(i);
	}

	it = a.begin();
	ASSERT_EQUAL(*it, 5);
	it++;
	ASSERT_EQUAL(*it, 4);

END_TEST

bool IsEven (int i) 
{
  return ((i % 2) == 0);
}
BEGIN_TEST(find_if)
	
	LinkedList a;
	
	for (size_t i = 1; i < 6; i++)
	{
		a.add(i);
	}
	
	Iterator it = std::find_if (a.begin(), a.end(), IsEven);
	std::cout << "the first: " << *it << '\n';
	ASSERT_EQUAL(*it, 4);

END_TEST


BEGIN_SUITE(Its counts)

IGNORE_TEST(empty_list)
IGNORE_TEST(add_and_remove)
IGNORE_TEST(all_function)
IGNORE_TEST(test_cctor)
IGNORE_TEST(test_operator_equal)
IGNORE_TEST(test_find)
IGNORE_TEST(test_united)
TEST(iterator_add)
TEST(find_if)

END_SUITE



