#include "mu_test.h"
#include "biginteger.hpp"
#include "single_list.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>

/*------------------------------------*/
BEGIN_TEST(add_bigs)
    BigInteger a(14);
	BigInteger b(13);
	BigInteger c;
	c = a.add(b);
	c.printList();
	LinkedList d = c.getList(); 
	ASSERT_EQUAL(d.first(), 7);

END_TEST

BEGIN_TEST(add_bigs_overflow)
    BigInteger a(14);
	BigInteger b(19);
	BigInteger c;
	c = a.add(b);
	c.printList();
	LinkedList d = c.getList(); 
	ASSERT_EQUAL(d.first(), 3);

END_TEST

BEGIN_TEST(mul_bigs)
    BigInteger a(15);
	BigInteger b(15);
	BigInteger c;
	c = a.mul(b);
	c.printList();
	LinkedList d = c.getList(); 
	ASSERT_EQUAL(d.first(), 2);

END_TEST

BEGIN_SUITE(iption)
	TEST(add_bigs)
	TEST(add_bigs_overflow)
	TEST(mul_bigs)
END_SUITE
