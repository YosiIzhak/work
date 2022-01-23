#include <stdio.h>
#include <stdlib.h>
#include "../../inc/rational.hpp"
#include "../mu_test.h"


BEGIN_TEST(AddRational)
	int a, b;
    Rational num(1, 2);
    Rational num1(1, 4);
    Rational res = num.add(num1);
    a = res.get_num();
    b = res.get_den();
    ASSERT_EQUAL(3, a);
    ASSERT_EQUAL(4, b);
    
END_TEST

BEGIN_TEST(AddNeg)
	int a, b;
    Rational num(-1, 4);
    Rational num1(3, 6);
    Rational res = num.add(num1);
    a = res.get_num();
    b = res.get_den();
    ASSERT_EQUAL(1, a);
    ASSERT_EQUAL(4, b);
    
END_TEST

BEGIN_TEST(Sub)
	int a, b;
    Rational num(5, 7);
    Rational num1(2, 5);
    Rational res = num.sub(num1);
    a = res.get_num();
    b = res.get_den();
    ASSERT_EQUAL(11, a);
    ASSERT_EQUAL(35, b);
    
END_TEST
BEGIN_TEST(Inverse)
	int a, b;
    Rational num(2, 4);
    Rational res = num.inv();
    a = res.get_num();
    b = res.get_den();
    ASSERT_EQUAL(2, a);
    ASSERT_EQUAL(1, b);
    
END_TEST

BEGIN_TEST(Multi)
	int a, b;
    Rational num(2, 4);
    Rational num1(1, 4);
    Rational res = num.mul(num1);
    a = res.get_num();
    b = res.get_den();
    ASSERT_EQUAL(1, a);
    ASSERT_EQUAL(8, b);
    
END_TEST

BEGIN_SUITE(不耻下问 this is a description)
   TEST(AddRational)
   TEST(Inverse)
   TEST(Multi)
   TEST(Sub)
   TEST(AddNeg)
END_SUITE


