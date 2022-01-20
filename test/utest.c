#include "mu_test.h"

#include "stack.h"


BEGIN_TEST(add_small_int)
    int a = 4;
    int b = 6;

    int r = add(&a, &b);
    ASSERT_EQUAL(r, 10);

    ASSERT_NOT_EQUAL(r, 0);
    ASSERT_THAT(r > 0);
    ASSERT_THAT(r < 20);

END_TEST


BEGIN_TEST(add_array_elemnts)
    int a[5] = {1,2,3,4,5};


    int r = add(a+1, a+2);
    ASSERT_EQUAL(r, 5);

    r = add(a, a+3);
    ASSERT_EQUAL(r, 5);
END_TEST


BEGIN_TEST(add_elem_and_null)
    int a = 7;

    int r = add(&a, 0);

    ASSERT_EQUAL(r, 10);
END_TEST


BEGIN_TEST(add_with_FAIL)
    int a = 7;

    int r = add(0, 0);
    if(r < -100){
        ASSERT_EQUAL(r, -42);
    }else{
        ASSERT_FAIL("should not be here");
    }

END_TEST

BEGIN_TEST(fake_test)
    int a = 8;
    int b = 7;
    int r = add(&a, &b);
    ASSERT_PASS();

END_TEST


BEGIN_SUITE(不耻下问 this is a description)
    TEST(add_elem_and_null)
    IGNORE_TEST(add_small_int)
    TEST(add_array_elemnts)
    TEST(add_with_FAIL)
    TEST(fake_test)
END_SUITE
