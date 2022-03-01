#include "mu_test.h"
#include "para_algo.hpp"
#include <pthread.h>

BEGIN_TEST(vec_thread_2)
	using namespace cpp;
	const size_t NUM_OF_THREADS = 2;
  std::vector<int> vec(1000000);
  size_t v_size = vec.size(); 
  for(size_t i = 1; i <= v_size; ++i)
  {
	  vec.push_back(i);
  }
   
  size_t sum = sumVector(vec, NUM_OF_THREADS);
	std::cout<< sum  << std::endl;
	ASSERT_PASS();
END_TEST

BEGIN_TEST(vec_thread_1000)
	using namespace cpp;
	const size_t NUM_OF_THREADS = 4;
  std::vector<int> vec(1000);
  size_t v_size = vec.size(); 
  for(size_t i = 1; i <= v_size; ++i)
  {
	  vec.push_back(i);
  }
   
  size_t sum = sumVector(vec, NUM_OF_THREADS);
	std::cout<< sum  << std::endl;
	ASSERT_PASS();
END_TEST

BEGIN_TEST(vec_thread_4)
	using namespace cpp;
	const size_t NUM_OF_THREADS = 4;
  std::vector<int> vec(1000000);
  size_t v_size = vec.size(); 
  for(size_t i = 1; i <= v_size; ++i)
  {
	  vec.push_back(i);
  }
   
  size_t sum = sumVector(vec, NUM_OF_THREADS);
	std::cout<< sum  << std::endl;
	ASSERT_PASS();
END_TEST

BEGIN_TEST(vec_thread_16)
	using namespace cpp;
	const size_t NUM_OF_THREADS = 16;
  std::vector<int> vec(1000000);
  size_t v_size = vec.size(); 
  for(size_t i = 1; i <= v_size; ++i)
  {
	  vec.push_back(i);
  }
   
  size_t sum = sumVector(vec, NUM_OF_THREADS);
	std::cout<< sum  << std::endl;
	ASSERT_PASS();
END_TEST

BEGIN_SUITE(不耻下问 this is a description)
 	
 	TEST(vec_thread_2)
	TEST(vec_thread_1000)
	TEST(vec_thread_4)
	TEST(vec_thread_16)

END_SUITE
