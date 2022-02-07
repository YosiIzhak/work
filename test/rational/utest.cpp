#include <stdio.h>
#include <stdlib.h>
#include "rational.hpp"
#include "mu_test.h"



BEGIN_TEST(add_operator)

 	Rational a(1, 4);
	Rational b(1, 3);
	a = a + b;
	a.reduce();
	a.display();
  	
    ASSERT_EQUAL(a.getNumerator(), 7); 
    ASSERT_EQUAL(a.getDenominator(), 12); 
   
END_TEST

BEGIN_TEST(sub_operator)

 	Rational a(1, 2);
	Rational b(1, 3);
	a = a - b;
	a.reduce();
	a.display();
  	
    ASSERT_EQUAL(a.getNumerator(), 1); 
    ASSERT_EQUAL(a.getDenominator(), 6); 
   
END_TEST

BEGIN_TEST(mul_operator)

 	Rational a(1, 2);
	Rational b(3, 4);
	a = a * b;
	a.reduce();
	a.display();
  	
    ASSERT_EQUAL(a.getNumerator(), 3); 
    ASSERT_EQUAL(a.getDenominator(), 8); 
   
END_TEST

BEGIN_TEST(div_operator)

 	Rational a(6, 8);
	Rational b(3, 1);
	a = a / b;
	a.reduce();
	a.display();
  	
    ASSERT_EQUAL(a.getNumerator(), 1); 
    ASSERT_EQUAL(a.getDenominator(), 4); 
   
END_TEST
BEGIN_TEST(add_operator_assign)

 	Rational a(1, 4);
	Rational b(1, 3);
	 a += b;
	a.reduce();
	a.display();
  	
    ASSERT_EQUAL(a.getNumerator(), 7); 
    ASSERT_EQUAL(a.getDenominator(), 12); 
   
END_TEST
BEGIN_TEST(sub_operator_assign)

 	Rational a(1, 2);
	Rational b(1, 3);
	 a -= b;
	a.reduce();
	a.display();
  	
    ASSERT_EQUAL(a.getNumerator(), 1); 
    ASSERT_EQUAL(a.getDenominator(), 6); 
   
END_TEST

BEGIN_TEST(mul_operator_assign)

 	Rational a(1, 2);
	Rational b(3, 4);
	 a *= b;
	a.reduce();
	a.display();
  	
    ASSERT_EQUAL(a.getNumerator(), 3); 
    ASSERT_EQUAL(a.getDenominator(), 8); 
   
END_TEST

BEGIN_TEST(div_operator_assign)

 	Rational a(6, 8);
	Rational b(3, 1);
	 a /= b;
	a.reduce();
	a.display();
  	
    ASSERT_EQUAL(a.getNumerator(), 1); 
    ASSERT_EQUAL(a.getDenominator(), 4); 
   
END_TEST
BEGIN_TEST(inc_operator_pre)

 	Rational a(1, 4);
	Rational r = ++a;

	r.reduce();
	r.display();
  	
    ASSERT_EQUAL(r.getNumerator(), 5); 
    ASSERT_EQUAL(r.getDenominator(), 4); 
   
END_TEST
BEGIN_TEST(inc_operator_post)

 	Rational a(1, 4);
	Rational r = a++;

	r.reduce();
	r.display();
  	
    ASSERT_EQUAL(r.getNumerator(), 1); 
    ASSERT_EQUAL(r.getDenominator(), 4); 
   
END_TEST
BEGIN_TEST(dec_operator_pre)

 	Rational a(1, 4);
	Rational r = --a;

	r.reduce();
	r.display();
  	
    ASSERT_EQUAL(r.getNumerator(), -3); 
    ASSERT_EQUAL(r.getDenominator(), 4); 
   
END_TEST
BEGIN_TEST(dec_operator_post)

 	Rational a(1, 4);
	Rational r = a--;

	r.reduce();
	r.display();
  	
    ASSERT_EQUAL(r.getNumerator(), 1); 
    ASSERT_EQUAL(r.getDenominator(), 4); 
   
END_TEST
BEGIN_TEST(inv_operator)

 	Rational a(1, 4);
	Rational r = -a;

	r.reduce();
	r.display();
  	
    ASSERT_EQUAL(r.getNumerator(), -1); 
    ASSERT_EQUAL(r.getDenominator(), 4); 
   
END_TEST
BEGIN_TEST(equal_operator)

 	Rational a(1, 4);
	Rational r(3, 12);

	r.reduce();
	r.display();
  	bool res = a == r;
    ASSERT_EQUAL(res, true); 
     
END_TEST
BEGIN_TEST(not_equal_operator)

 	Rational a(1, 4);
	Rational r(2, 12);

	r.reduce();
	r.display();
  	bool res = a == r;
    ASSERT_EQUAL(res, false); 
   
   
END_TEST
BEGIN_TEST(less_operator)

 	Rational a(1, 4);
	Rational r(2, 12);

	r.reduce();
	r.display();
  	bool res = a < r;
    ASSERT_EQUAL(res, false); 
      
END_TEST
BEGIN_TEST(greater_operator)

 	Rational a(1, 4);
	Rational r(2, 12);

	r.reduce();
	r.display();
  	bool res = a > r;
    ASSERT_EQUAL(res, true); 
      
END_TEST
BEGIN_TEST(greater_equal_operator)

 	Rational a(1, 4);
	Rational r(2, 12);

	r.reduce();
	r.display();
  	bool res = a >= r;
    ASSERT_EQUAL(res, true); 
      
END_TEST
BEGIN_TEST(less_equal_operator)

 	Rational a(1, 4);
	Rational r(2, 12);

	r.reduce();
	r.display();
  	bool res = a <= r;
    ASSERT_EQUAL(res, false); 
      
END_TEST
BEGIN_TEST(global_add_operator)

 	Rational a(1, 4);
	Rational b(2, 12);
	Rational c = a + b;
	c.reduce();
	c.display();
    ASSERT_EQUAL(c.getNumerator(), 5); 
    ASSERT_EQUAL(c.getDenominator(), 12); 
      
END_TEST
BEGIN_SUITE(Its what you learn after you know it all that counts)

	
	TEST(add_operator)
	TEST(sub_operator)
	TEST(mul_operator)
    TEST(div_operator)
	TEST(add_operator_assign)
	TEST(sub_operator_assign)
	TEST(mul_operator_assign)
	TEST(div_operator_assign)
	TEST(inc_operator_pre)
	TEST(inc_operator_post)
	TEST(dec_operator_pre)
	TEST(dec_operator_post)
	TEST(inv_operator)
	TEST(equal_operator)
	TEST(not_equal_operator)
	TEST(less_operator)
	TEST(greater_operator)
	TEST(greater_equal_operator)
	TEST(less_equal_operator)
	TEST(global_add_operator)
END_SUITE


