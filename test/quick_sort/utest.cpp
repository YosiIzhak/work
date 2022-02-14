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

	char arr[] = "nmlkjihgfedcba";

	quickSort<char>(arr, 14);

	for (int i = 0; i < 14; i++)
	{
		std::cout << "arr[" << i << "] :" << arr[i] << "\n";
	}
	ASSERT_PASS();

END_TEST


BEGIN_TEST(ball_sort_test)

	using namespace cpp;

	Ball arr[10];
	arr[0].setRadius(4);
	arr[1].setRadius(7);
	arr[2].setRadius(3);
	arr[3].setRadius(8);
	arr[4].setRadius(5);
	arr[5].setRadius(6);
	arr[6].setRadius(2);
	arr[7].setRadius(9);
	arr[8].setRadius(1);
	arr[9].setRadius(10);

	quickSort<Ball>(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		std::cout << "arr[" << i << "] :" << arr[i].getRadius() << "\n";
	}

	ASSERT_PASS();

END_TEST

BEGIN_TEST(point_sort_test)

	using namespace cpp;

	Point<double> arr[10];
	arr[0].setPoint(4, 4);
	arr[1].setPoint(1, 1);
	arr[2].setPoint(10, 10);
	arr[3].setPoint(7, 7);
	arr[4].setPoint(6, 6);
	arr[5].setPoint(9, 9);
	arr[6].setPoint(3, 3);
	arr[7].setPoint(2, 2);
	arr[8].setPoint(5, 5);
	arr[9].setPoint(8, 8);

	quickSort<Point<double> >(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		std::cout << "arr[" << i << "] :" << arr[i].getX() << ", " << arr[i].getY() << "\n";
	}
	
	ASSERT_PASS();

END_TEST




BEGIN_SUITE(TEST)

	TEST(int_sort_test)
	TEST(char_sort_test)
	TEST(ball_sort_test)
	TEST(point_sort_test)

END_SUITE