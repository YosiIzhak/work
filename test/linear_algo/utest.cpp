#include "mu_test.h"
#include "utils.hpp"
#include <vector>
#include "linear_algo.hpp"

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
    oddOut(int_vector, N);
    for (size_t i = 0; i < int_vector.size(); i++)
    {
        std::cout << int_vector[i] <<" item\n ";
    }

END_TEST

BEGIN_TEST(min_max)
    
    using std::vector;
    using namespace cpp;

    int const N = 10;
    vector<int> int_vector;
    int_vector.reserve(N);
    int_vector.push_back(1); 
    int_vector.push_back(4);
    int_vector.push_back(6);
    int_vector.push_back(3);
    int_vector.push_back(6);
    int_vector.push_back(8);
    int_vector.push_back(9);
    int_vector.push_back(9);
    int_vector.push_back(6);
    int_vector.push_back(4);
    ASSERT_EQUAL(int_vector.size(), N);
    int min, max;
    extremes(int_vector, min, max);
    ASSERT_EQUAL(max, 9);
    ASSERT_EQUAL(min, 1);
    
END_TEST

BEGIN_TEST(duplicate_test)
    
    using std::vector;
    using namespace cpp;
    
    int const N = 10;
    vector<int> int_vector;
    int_vector.push_back(1); 
    int_vector.push_back(4);
    int_vector.push_back(6);
    int_vector.push_back(3);
    int_vector.push_back(6);
    int_vector.push_back(8);
    int_vector.push_back(9);
    int_vector.push_back(9);
    int_vector.push_back(6);
    int_vector.push_back(4);
    int_vector.reserve(N);
   
    ASSERT_EQUAL(int_vector.size(), N);
    int first;
    first = firstDuplicate(int_vector);
    std::cout << first <<" first\n ";
        
END_TEST
BEGIN_SUITE(TEST)

	TEST(random_vector)
    TEST(sum_random_vector)
    TEST(odd_out)
    TEST(min_max)
    TEST(duplicate_test)
	
END_SUITE
