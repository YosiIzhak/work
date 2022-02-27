#include "mu_test.h"
#include "sorted_container.hpp"
#include "sorted_list.hpp"
#include "sorted_vector.hpp"
#include "sorted_unique_vector.hpp"
#include "sorted_unique_list.hpp"

BEGIN_TEST(vec_new)
	using namespace cpp;
	SortedVector<int> vec(10);
	ASSERT_EQUAL(vec.size(), 0);
	vec.insert(7);
	ASSERT_EQUAL(vec.size(), 1);
	ASSERT_PASS();
	
END_TEST

BEGIN_SUITE(不耻下问 this is a description)
 	
 	 TEST(vec_new)
   
END_SUITE
