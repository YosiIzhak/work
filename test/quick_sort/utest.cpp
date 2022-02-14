#include "mu_test.h"
#include "quick_sort.hpp"
#include "ball.hpp"
#include "point.hpp"

BEGIN_TEST(int_sort_test)

	using namespace cpp;

	int array[] = {1,4,9,2,3,8,0,-1,7,-4,5,-2,6,-3,10};
	quickSort<int>(array, 15);
	for (int i = 0; i < 15; i++)
	{
		std::cout << "arr[" << i << "] :" << array[i] << "\n";
	}

	ASSERT_PASS();

END_TEST


BEGIN_TEST(char_sort_test)

	using namespace cpp;

	char array[] = "nmlkjihgfedcba";

	quickSort<char>(array, 14);

	for (int i = 0; i < 14; i++)
	{
		std::cout << "arr[" << i << "] :" << array[i] << "\n";
	}
	ASSERT_PASS();

END_TEST


BEGIN_TEST(ball_sort_test)

	using namespace cpp;

	Ball array[10];
	array[0].setRadius(4);
    array[0].setColor('red');
	array[1].setRadius(7);
	array[1].setColor('blue');
    array[2].setRadius(3);
	array[2].setColor('yellow');
    array[3].setRadius(8);
	array[3].setColor('green');
    array[4].setRadius(5);
	array[5].setRadius(6);
	array[6].setRadius(2);
	array[7].setRadius(9);
	array[8].setRadius(1);
	array[9].setRadius(10);

	quickSort<Ball>(array, 10);

	for (int i = 0; i < 10; i++)
	{
		std::cout << "arr[" << i << "] :" << array[i].getRadius() << "\n";
	}

	ASSERT_PASS();

END_TEST

BEGIN_TEST(point_sort_test)

	using namespace cpp;

	Point<double> array[10];
	array[0].setPoint(4, 4);
	array[1].setPoint(1, 1);
	array[2].setPoint(10, 10);
	array[3].setPoint(7, 7);
	array[4].setPoint(6, 6);
	array[5].setPoint(9, 9);
	array[6].setPoint(3, 3);
	array[7].setPoint(2, 2);
	array[8].setPoint(5, 5);
	array[9].setPoint(8, 8);

	quickSort<Point<double> >(array, 10);

	for (int i = 0; i < 10; i++)
	{
		std::cout << "array[" << i << "] :" << array[i].getX() << ", " << array[i].getY() << "\n";
	}
	
	ASSERT_PASS();

END_TEST




BEGIN_SUITE(TEST)

	TEST(int_sort_test)
	TEST(char_sort_test)
	TEST(ball_sort_test)
	TEST(point_sort_test)

END_SUITE