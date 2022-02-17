#include "mu_test.h"
#include "utils.hpp"
#include "ball.hpp"
#include "linear_algo.hpp"
#include "quick_sort.hpp"
#include <vector>
BEGIN_TEST(random_vector)
   
    using std::vector;
	using namespace cpp;

    int const N = 100;
    vector<double> double_vector;
    double_vector.reserve(N);
    createChaos(double_vector, N);
    ASSERT_EQUAL(double_vector.size(), N);
END_TEST


BEGIN_TEST(sum_random_vector)
    
    using std::vector;
    using namespace cpp;

    int const N = 100;
    vector<double> double_vector;
    double_vector.reserve(N);
    createChaos(double_vector, N);
    ASSERT_EQUAL(double_vector.size(), N);
    double res = sum(double_vector, N);
    std::cout << res <<" res ";
END_TEST

BEGIN_TEST(odd_out)
    
    using std::vector;
    using namespace cpp;

    int const N = 10;
    vector<int> int_vector;
    int_vector.reserve(N);
    createChaos(int_vector, N);
    ASSERT_EQUAL(int_vector.size(), N);
    oddsOut(int_vector, N);
    for (size_t i = 0; i < int_vector.size(); i++)
    {
        std::cout << int_vector[i] <<" item\n ";
    }

END_TEST

BEGIN_TEST(min_max)
    
    using std::vector;
    using namespace cpp;

    int const N = 10;
    int numbs[] = {1,2,4,6,3,7,7,8,9,1};
    vector<int> int_vector(numbs, numbs+10);
    int_vector.reserve(N);
    
    ASSERT_EQUAL(int_vector.size(), N);
    std::pair<size_t, size_t> p = extremes(int_vector);
    ASSERT_EQUAL(p.first, 1);
    ASSERT_EQUAL(p.second, 9);
    
END_TEST

BEGIN_TEST(min_max_2)
    
    using std::vector;
    using namespace cpp;

    int const N = 10;
    int numbs[] = {1,2,4,6,3,7,7,8,9,1};
    vector<size_t> int_vector(numbs, numbs+10);
    int_vector.reserve(N);
    
    ASSERT_EQUAL(int_vector.size(), N);
    std::pair<size_t, size_t> p = extremes2(int_vector);
    ASSERT_EQUAL(p.first, 1);
    ASSERT_EQUAL(p.second, 9);
    
END_TEST

BEGIN_TEST(duplicate_int)
    
    using std::vector;
    using namespace cpp;
    
    int const N = 10;
    int numbs[] = {1,2,4,6,3,7,7,8,9,1};
    vector<int> int_vector(numbs, numbs+10);
   
    int_vector.reserve(N);
   
    ASSERT_EQUAL(int_vector.size(), N);
    int first;
    first = firstDuplicate(int_vector);
    std::cout << first <<" first\n ";
        
END_TEST

// BEGIN_TEST(ball_duplicate)

//      using std::vector;
// 	using namespace cpp;

//      int const N = 10;
// 	Ball array[10];
// 	array[0].setRadius(4);
// 	array[1].setRadius(7);
// 	array[2].setRadius(3);
// 	array[3].setRadius(8);
// 	array[4].setRadius(5);
// 	array[5].setRadius(6);
// 	array[6].setRadius(2);
// 	array[7].setRadius(9);
// 	array[8].setRadius(7);
// 	array[9].setRadius(10);
//     ASSERT_EQUAL(array.size(), N);
//     int first;
//     first = firstDuplicate(array);
//     std::cout << first <<" first\n ";

// END_TEST

BEGIN_SUITE(TEST)

	TEST(random_vector)
    TEST(sum_random_vector)
    TEST(odd_out)
    TEST(min_max)
    TEST(duplicate_int)
    TEST(min_max_2)
    //TEST(ball_duplicate)
	
END_SUITE
