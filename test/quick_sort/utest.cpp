#include "mu_test.h"
#include "quick_sort.hpp"
#include "ball.hpp"
#include "point.hpp"
#include <cstdio>
#include <cstdlib>
#include <cassert>

/*------------------------------------*/
using namespace cpp;
BEGIN_TEST(new_sort)
   
    int array[] = {1,11,44,33,66,77,99,22,55};
    size_t n = (sizeof(array) / sizeof(array[0]));
    quickSort(array, n);
    quickPrint(array, n);
	ASSERT_EQUAL(true, true);
END_TEST

BEGIN_TEST(char_sort)
   
    char array[] = {'a', 'd', 'h', 'u', 'r','c'};
    size_t n = (sizeof(array) / sizeof(array[0]));
    quickSort(array, n);
    charPrint(array, n);
	ASSERT_EQUAL(true, true);
END_TEST


BEGIN_TEST(ball_sort)
    Ball array[] = {{"red",5},{"yellow", 2}, {"blue", 9}};
    size_t n = (sizeof(array) / sizeof(array[0]));
    quickSort(array, n);
    quickPrint(array, n);
	ASSERT_EQUAL(true, true);
END_TEST
BEGIN_SUITE(option)
	
	TEST(new_sort)
    TEST(char_sort)
    TEST(ball_sort)

END_SUITE
