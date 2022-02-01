#include "mu_test.h"
#include "single_list.hpp"

BEGIN_TEST(empty_list)

	List list;
    ListItr itr;
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_THAT(list.isEmpty());
END_TEST

BEGIN_TEST(add_and_remove)

	List list;
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_THAT(list.isEmpty());
	for (int i = 1; i < 11; i++)
	{
		list.add(i);
	}
	ASSERT_EQUAL(list.size(), 10);
	ASSERT_THAT(!list.isEmpty());

	for (int i = 1; i < 11; i++)
	{
		list.remove();
	}
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_THAT(list.isEmpty());

END_TEST

BEGIN_TEST(all_function)

	List list;
	ASSERT_EQUAL(list.size(), 0);
	ASSERT_EQUAL(list.isEmpty(), true);

	ListItr it;
	it = list.begin();
	ASSERT_EQUAL(it.get(), 0);
	it = list.end();
	ASSERT_EQUAL(it.get(), 0);
	ASSERT_EQUAL(it.equals(list.begin()), true);
	ASSERT_EQUAL(!it.equals(list.begin()), false);

	for (int i = 1; i < 11; i++)
	{
		list.add(i);
        list.print();
    }
	ASSERT_EQUAL(list.size(), 10);
	ASSERT_EQUAL(list.isEmpty(), false);
	ASSERT_EQUAL(list.first(), 10);
	ASSERT_EQUAL(list.last(), 1);

	it = list.begin();
	ASSERT_EQUAL(it.get(), 10);
	it = it.next();
	ASSERT_EQUAL(it.get(), 9);
	it = list.end();
	ASSERT_EQUAL(it.get(), 0);
	ASSERT_EQUAL(it.equals(list.begin()), false);
	ASSERT_EQUAL(!it.equals(list.begin()), true);

	it = list.begin();
	int r;
	for (int i = 10; i > 0; i--)
	{
		r = it.get();
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
	ASSERT_EQUAL(it.get(), 0);

END_TEST



BEGIN_TEST(test_operator_equal)

	List a;
	List b;

	for (size_t i = 1; i < 6; i++)
	{
		b.add(i);
	}

	a = b;
	ASSERT_EQUAL(b.size(), 5);
	ASSERT_EQUAL(a.size(), 5);

END_TEST

BEGIN_SUITE(Its what you )

IGNORE_TEST(empty_list)
TEST(add_and_remove)
TEST(all_function)
TEST(test_operator_equal)

END_SUITE



