#include <stdio.h>
#include <stdlib.h>
#include "../../inc/rational.hpp"
#include "../mu_test.h"

BEGIN_TEST(add_test_positive_rational)

	Rational r(1, 2, true);

        ASSERT_EQUAL(r.getNumerator(), 1);
        ASSERT_EQUAL(r.getDenominator(), 2);

        r = Rational(5,10);

        ASSERT_EQUAL(r.getNumerator(), 1);
        ASSERT_EQUAL(r.getDenominator(), 2);

        r = Rational(7,32);

        ASSERT_EQUAL(r.getNumerator(), 7);
        ASSERT_EQUAL(r.getDenominator(), 32);

        r = Rational(-7, -32);

        ASSERT_EQUAL(r.getNumerator(), 7);
        ASSERT_EQUAL(r.getDenominator(), 32);

END_TEST

BEGIN_TEST(create_a_zero_test)

	Rational r(0, 2);

        ASSERT_EQUAL(r.getNumerator(), 0);
        ASSERT_EQUAL(r.getDenominator(), 1);

        r = Rational(0, 12);

        ASSERT_EQUAL(r.getNumerator(), 0);
        ASSERT_EQUAL(r.getDenominator(), 1);

END_TEST


BEGIN_TEST(create_infinity_test)

	Rational r(1, 0);
	ASSERT_FAIL("can't divide by zero");

END_TEST

BEGIN_TEST(add_test_negative_rational)

	Rational r = Rational(-1,2);

        ASSERT_EQUAL(r.getNumerator(), -1);
        ASSERT_EQUAL(r.getDenominator(), 2);

        r = Rational(5, -10);

        ASSERT_EQUAL(r.getNumerator(), -1);
        ASSERT_EQUAL(r.getDenominator(), 2);

        r = Rational(7, -32);

        ASSERT_EQUAL(r.getNumerator(), -7);
        ASSERT_EQUAL(r.getDenominator(), 32);

END_TEST

BEGIN_TEST(default_parameters)

        Rational zero;    // == one(0, 1)
        Rational one(1);  // == one(1, 1)
        Rational w(2);    // == one(2, 1)

        Rational q1(3, 4);
		Rational q2(3, 4);
		Rational q3(3, 4);
		Rational q4(3, 4);

        q2.mul(one);
        q3.mul(zero);
		q4.mul(zero);

        ASSERT_THAT(q1.compare(q2) == 0);
        ASSERT_THAT(q3.compare(zero) == 0);
		ASSERT_THAT(q4.compare(w) == -1);

END_TEST

BEGIN_TEST(add_positive_and_negative)

	Rational r1(2, 4);
	Rational r2(5, 10);
	r1.add(r2);
	ASSERT_EQUAL(r1.getNumerator(), 1);
    ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r1.add(r2);
	ASSERT_EQUAL(r1.getNumerator(), 0);
    ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r1.add(r2);
	ASSERT_EQUAL(r1.getNumerator(), 3);
    ASSERT_EQUAL(r1.getDenominator(), 56);

	r1 = Rational(3, -12);
	r2 = Rational(17,22);
	r1.add(r2);
	ASSERT_EQUAL(r1.getNumerator(), 23);
    ASSERT_EQUAL(r1.getDenominator(), 44);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r1.add(r2);
	ASSERT_EQUAL(r1.getNumerator(), -45);
    ASSERT_EQUAL(r1.getDenominator(), 44);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r1.add(r2);
	ASSERT_EQUAL(r1.getNumerator(), 67);
    ASSERT_EQUAL(r1.getDenominator(), 66);

END_TEST


BEGIN_TEST(sub_positive_and_negative)

	Rational r1(2, 4);
	Rational r2(5, 10);
	r1.sub(r2);
	ASSERT_EQUAL(r1.getNumerator(), 0);
    ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r1.sub(r2);
	ASSERT_EQUAL(r1.getNumerator(), 1);
    ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r1.sub(r2);
	ASSERT_EQUAL(r1.getNumerator(), -31);
    ASSERT_EQUAL(r1.getDenominator(), 56);

	r1 = Rational(3, -12);
	r2 = Rational(17,22);
	r1.sub(r2);
	ASSERT_EQUAL(r1.getNumerator(), -45);
    ASSERT_EQUAL(r1.getDenominator(), 44);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r1.sub(r2);
	ASSERT_EQUAL(r1.getNumerator(), 23);
    ASSERT_EQUAL(r1.getDenominator(), 44);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r1.sub(r2);
	ASSERT_EQUAL(r1.getNumerator(), -23);
    ASSERT_EQUAL(r1.getDenominator(), 66);

END_TEST


BEGIN_TEST(mul_positive_and_negative)

	Rational r1(2, 4);
	Rational r2(5, 10);
	r1.mul(r2);
	ASSERT_EQUAL(r1.getNumerator(), 1);
    ASSERT_EQUAL(r1.getDenominator(), 4);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r1.mul(r2);
	ASSERT_EQUAL(r1.getNumerator(), -1);
    ASSERT_EQUAL(r1.getDenominator(), 4);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r1.mul(r2);
	ASSERT_EQUAL(r1.getNumerator(), -17);
    ASSERT_EQUAL(r1.getDenominator(), 224);

	r1 = Rational(3, -12);
	r2 = Rational(17,22);
	r1.mul(r2);
	ASSERT_EQUAL(r1.getNumerator(), -17);
    ASSERT_EQUAL(r1.getDenominator(), 88);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r1.mul(r2);
	ASSERT_EQUAL(r1.getNumerator(), 17);
    ASSERT_EQUAL(r1.getDenominator(), 88);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r1.mul(r2);
	ASSERT_EQUAL(r1.getNumerator(), 5);
    ASSERT_EQUAL(r1.getDenominator(), 22);

END_TEST

BEGIN_TEST(div_positive_and_negative)

	Rational r1(2, 4);
	Rational r2(5, 10);
	r1.div(r2);
	ASSERT_EQUAL(r1.getNumerator(), 1);
    ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = Rational(2, 4);
	r2 = Rational(5, -10);
	r1.div(r2);
	ASSERT_EQUAL(r1.getNumerator(), -1);
    ASSERT_EQUAL(r1.getDenominator(), 1);

	r1 = Rational(-3, 12);
	r2 = Rational(17, 56);
	r1.div(r2);
	ASSERT_EQUAL(r1.getNumerator(), -14);
    ASSERT_EQUAL(r1.getDenominator(), 17);

	r1 = Rational(3, -12);
	r2 = Rational(17,22);
	r1.div(r2);
	ASSERT_EQUAL(r1.getNumerator(), -11);
    ASSERT_EQUAL(r1.getDenominator(), 34);

	r1 = Rational(3, -12);
	r2 = Rational(-17, 22);
	r1.div(r2);
	ASSERT_EQUAL(r1.getNumerator(), 11);
    ASSERT_EQUAL(r1.getDenominator(), 34);

	r1 = Rational(-3, -9);
	r2 = Rational(-15, -22);
	r1.div(r2);
	ASSERT_EQUAL(r1.getNumerator(), 22);
    ASSERT_EQUAL(r1.getDenominator(), 45);

END_TEST

BEGIN_TEST(isEqual)

	Rational h(2, 4);
	Rational q(2, 8);

	h.add(q);
	Rational q34(3, 4);
	Rational q34copy = q34;

	ASSERT_THAT(q34.equal(h));
	ASSERT_THAT(q34.equal(q34copy));

END_TEST



/*BEGIN_TEST(is_add_work)

 	Rational a = Rational(1, 4) ;
  	Rational b = Rational(1, 4) ;
  	Rational c = b.Add(a);
  	
	ASSERT_EQUAL(c.GetNumerator(), 1); 
    	ASSERT_EQUAL(c.GetDenominator(), 2);  
      
END_TEST


BEGIN_TEST(is_add_with_negative_work)

 	Rational a = Rational(-1, 4) ;
  	Rational b = Rational(3, 6) ;
  	Rational c = b.Add(a);
  	
	ASSERT_EQUAL(c.GetNumerator(),1); 
    	ASSERT_EQUAL(c.GetDenominator(), 4);  
      
END_TEST


BEGIN_TEST(is_sub_work)

 	Rational a = Rational(3, 4) ;
  	Rational b = Rational(1, 4) ;
  	Rational c = a.Sub(b);
  	
	ASSERT_EQUAL(c.GetNumerator(), 1); 
    	ASSERT_EQUAL(c.GetDenominator(), 2); 

     
END_TEST


BEGIN_TEST(is_sub_with_negative_work)

 	Rational a = Rational(-18, 12) ;
  	Rational b = Rational(1, 24) ;
  	Rational c = a.Sub(b);
  	
	ASSERT_EQUAL(c.GetNumerator(),-37); 
    	ASSERT_EQUAL(c.GetDenominator(), 24); 

     
END_TEST


BEGIN_TEST(is_mul_work)

 	Rational a = Rational(2, 10) ;
  	Rational b = Rational(6, 10) ;
  	Rational c = a.Mul(b);
  	
	ASSERT_EQUAL(c.GetNumerator(), 3); 
    	ASSERT_EQUAL(c.GetDenominator(), 25); 

     
END_TEST


BEGIN_TEST(is_mul_with_negative_work)

 	Rational a = Rational(-2, 10) ;
  	Rational b = Rational(6, 10) ;
  	Rational c = a.Mul(b);
  	
	ASSERT_EQUAL(c.GetNumerator(), -3); 
    	ASSERT_EQUAL(c.GetDenominator(), 25); 

     
END_TEST


BEGIN_TEST(is_reduce_work)

 	Rational a = Rational(8, 16) ;
  	a.Reduce();
  	
	ASSERT_EQUAL(a.GetNumerator(), 1); 
    	ASSERT_EQUAL(a.GetDenominator(), 2); 
   
END_TEST


BEGIN_TEST(is_reduce_with_negative_work)

 	Rational a = Rational(-8, 16) ;
  	a.Reduce();
  	
	ASSERT_EQUAL(a.GetNumerator(), -1); 
    	ASSERT_EQUAL(a.GetDenominator(), 2); 
   
END_TEST


BEGIN_TEST(is_invers_work)

 	Rational a = Rational(3, 4) ;
  	a.Inverse();
  	
	ASSERT_EQUAL(a.GetNumerator(), 4); 
    	ASSERT_EQUAL(a.GetDenominator(), 3); 
   
END_TEST


BEGIN_TEST(is_invers_with_negative_work)

 	Rational a = Rational(-3, 4) ;
  	a.Inverse();
  	
	ASSERT_EQUAL(a.GetNumerator(), 4); 
    	ASSERT_EQUAL(a.GetDenominator(), -3); 
   
END_TEST


BEGIN_TEST(is_display_work)

 	Rational a = Rational(1, 4) ;
 	a.Display();
  	
    	ASSERT_PASS(); 
   
END_TEST


BEGIN_TEST(is_display_with_negative_work)

 	Rational a = Rational(1, -4) ;
 	a.Display();
  	
    	ASSERT_PASS(); 
   
END_TEST*/
     
     
BEGIN_SUITE(Its what you learn after you know it all that counts)

	TEST(add_test_positive_rational)
	TEST(create_a_zero_test)
	TEST(create_infinity_test)
	TEST(add_test_negative_rational)
	TEST(default_parameters)
	TEST(add_positive_and_negative)
	TEST(sub_positive_and_negative)
	TEST(mul_positive_and_negative)
	TEST(div_positive_and_negative)
	TEST(isEqual)
	/*TEST(is_add_work)
	TEST(is_add_with_negative_work)
	TEST(is_sub_work)
	TEST(is_sub_with_negative_work)
	TEST(is_mul_work)
	TEST(is_mul_with_negative_work)
	TEST(is_reduce_work)
	TEST(is_reduce_with_negative_work)
	TEST(is_invers_work)
	TEST(is_invers_with_negative_work)
	TEST(is_display_work)
	TEST(is_display_with_negative_work)*/
    
END_SUITE


