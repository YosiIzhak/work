#include "mu_test.h"
#include "biginteger.hpp"
#include "single_list.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>

/*------------------------------------*/
BEGIN_TEST(add_bigs)
    BigInteger a(75);
	BigInteger b(150);
	a.add(b);
	a.printList();
	LinkedList s = a.getList();
	ASSERT_EQUAL(s.first(),2);

END_TEST

BEGIN_TEST(add_bigs_overflow)
    BigInteger a(160);
	a.getList().print();
	//a.printList();
	BigInteger b(100);
	a.add(b);
	a.printList();
	
	ASSERT_EQUAL(a.getList().first(), 3);

END_TEST

BEGIN_TEST(mul_bigs)
    BigInteger a(15);
	//a.printList();
	BigInteger b(15);
	a.mul(b);
	a.printList();
	ASSERT_EQUAL(a.getList().first(), 2);

END_TEST

BEGIN_TEST(add_string)
    BigInteger a("75");
	a.printList();
	printf("-----------\n");
	BigInteger b("150");
	b.printList();
	printf("-----------\n");
	a.add(b);
	a.printList();
	LinkedList s = a.getList();
	ASSERT_EQUAL(s.first(),2);

END_TEST

BEGIN_TEST(equal_bigs)
    BigInteger a(75);
	a.printList();
	BigInteger b(75);
	b.printList();
	bool res = a.equal(b);
	
	ASSERT_EQUAL(res, true);

END_TEST

BEGIN_TEST(less_bigs)
    BigInteger a(15);
	BigInteger b(75);
	bool res = a.less(b);
	ASSERT_EQUAL(res, true);

END_TEST

BEGIN_TEST(test_operator_equal)

	BigInteger a;
	long b = 25;

	a = b;
	bool res = a.less(26);
	ASSERT_EQUAL(res, true);
	bool res1 = a.greater(24);
	ASSERT_EQUAL(res1, true);

END_TEST

BEGIN_TEST(test_assign)

	BigInteger a;
	BigInteger b(25);

	a = b;
	bool res = a.less(26);
	ASSERT_EQUAL(res, true);
	bool res1 = a.greater(24);
	ASSERT_EQUAL(res1, true);

END_TEST

BEGIN_SUITE(iption)
	IGNORE_TEST(add_bigs)
	IGNORE_TEST(add_bigs_overflow)
	IGNORE_TEST(mul_bigs)
	IGNORE_TEST(add_string)
	TEST(equal_bigs)
	TEST(less_bigs)
	TEST(test_operator_equal)
	TEST(test_assign)
END_SUITE
