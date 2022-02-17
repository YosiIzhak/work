#include "mu_test.h"
#include "utils.hpp"
#include "ball.hpp"
#include "linear_algo.hpp"
#include "quick_sort.hpp"
#include <vector>
BEGIN_TEST(random_vector)
   
    using std::vector;
	using namespace cpp;
     size_t const MAX = 10000;
    int const N = 100;
    vector<double> double_vector;
    double_vector.reserve(N);
    createChaos(double_vector, N, MAX);
    ASSERT_EQUAL(double_vector.size(), N);
END_TEST


BEGIN_TEST(sum_random_vector)
    
    using std::vector;
    using namespace cpp;
    size_t const MAX = 10000;
    int const N = 100;
    vector<double> double_vector;
    double_vector.reserve(N);
    createChaos(double_vector, N, MAX);
    ASSERT_EQUAL(double_vector.size(), N);
    double res = sum(double_vector, N);
    std::cout << res <<" res ";
END_TEST

BEGIN_TEST(odd_out)
    
    using std::vector;
    using namespace cpp;
     size_t const MAX = 10000;
    int const N = 10;
    vector<int> int_vector;
    int_vector.reserve(N);
    createChaos(int_vector, N, MAX);
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
    vector<size_t> int_vector(numbs, numbs+10);
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

BEGIN_TEST(firstDuplicate_test)

    using std::vector;
	using namespace cpp;

	size_t const N = 10000;
    vector<Ball> vec;
    vec.reserve(N);

	for(size_t i = 0; i < N; i++)
	{
		vec.push_back(Ball('w', i));
		if(i == N/2)
		{
			vec.push_back(Ball('w', i - 30));
			vec.push_back(Ball('w', i - 20));
			vec.push_back(Ball('w', i - 10));
			vec.push_back(Ball('w', i + 30));
			vec.push_back(Ball('w', i + 20));
			vec.push_back(Ball('w', i + 10));
			vec.push_back(Ball('w', i));
		}
	}
	size_t result = firstDuplicate<Ball>(vec);

	ASSERT_EQUAL(result,N/2 - 30);

END_TEST

BEGIN_TEST(count_test)
    
    using std::vector;
    using namespace cpp;
    
    int const N = 10;
    int v1[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> first(v1, v1+10);
    int v2[] = {1,3,5,7,9,11,34,65,19,14};
    vector<int> second(v2, v2+10);
    int v3[] = {1,2,40,60,4,74,71,8,9,12};
    vector<int> third(v3, v3+10);
    first.reserve(N);
    second.reserve(N);
    third.reserve(N);
    ASSERT_EQUAL(first.size(), N);
    ASSERT_EQUAL(second.size(), N);
    ASSERT_EQUAL(third.size(), N);

    size_t res;
    res = countCommontStrange(first, second, third);
    std::cout << res <<" res\n ";
        
END_TEST

BEGIN_SUITE(TEST)

	TEST(random_vector)
    TEST(sum_random_vector)
    TEST(odd_out)
    TEST(min_max)
    TEST(duplicate_int)
    TEST(min_max_2)
    TEST(firstDuplicate_test)
    TEST(count_test)
	
END_SUITE
