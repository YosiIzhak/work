#include "mu_test.h"
#include "single_list.hpp"

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

	ASSERT_THAT(a.isExist(5));
	ASSERT_THAT(!a.isExist(15));

END_TEST

BEGIN_TEST(test_united)

	LinkedList a;
	LinkedList b;
    LinkedList c;
	for (size_t i = 1; i < 6; i++)
	{
		a.add(i);
        a.print();
	}
	for (size_t i = 1; i < 6; i++)
	{
		b.add(i);
        b.print();
	}
    c = interSec(a, b);
    c.print();
    	
END_TEST
BEGIN_SUITE(Its counts)

IGNORE_TEST(empty_list)
TEST(add_and_remove)
TEST(all_function)
TEST(test_cctor)
TEST(test_operator_equal)
TEST(test_find)
TEST(test_united)

END_SUITE



