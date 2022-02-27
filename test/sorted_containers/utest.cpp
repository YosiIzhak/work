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


BEGIN_TEST(vec_unique)
	using namespace cpp;
	SortedUniqueVector<int> myvec(10);
	ASSERT_EQUAL(myvec.size(), 0);
	myvec.insert(7);
	ASSERT_EQUAL(myvec.size(), 1);
	myvec.insert(7);
	ASSERT_EQUAL(myvec.size(), 1);
	myvec.insert(8);
	ASSERT_EQUAL(myvec.size(), 2);

END_TEST

BEGIN_TEST(list_unique)
	using namespace cpp;
	SortedUniqueList<int> mylist;
	ASSERT_EQUAL(mylist.size(), 0);
	mylist.insert(7);
	ASSERT_EQUAL(mylist.size(), 1);
	mylist.insert(7);
	ASSERT_EQUAL(mylist.size(), 1);
	mylist.insert(8);
	ASSERT_EQUAL(mylist.size(), 2);

END_TEST

BEGIN_TEST(uniform_vec)
	using namespace cpp;
	SortedVector<int> vec(10);
	ASSERT_EQUAL(vec.size(), 0);
	vec.insert(7);
	ASSERT_EQUAL(vec.size(), 1);
	vec.insert(7);
	ASSERT_EQUAL(vec.size(), 2);
	vec.insert(7);
	ASSERT_EQUAL(vec.size(), 3);
	bool res = vec.isUniform();
	ASSERT_EQUAL(res, true);

END_TEST

BEGIN_SUITE(不耻下问 this is a description)
 	
 	TEST(vec_new)
	TEST(vec_unique)
	TEST(list_unique)
    TEST(uniform_vec)

END_SUITE
