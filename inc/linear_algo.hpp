#ifndef LINEAR_ALGO_HPP
#define LINEAR_ALGO_HPP
#include <cstdlib> //size_t
#include <vector>
#include "utils.hpp"

namespace cpp
{

template <typename T>
void createChaos(std::vector<T> &a_vector, size_t a_size);

template <typename T>
double sum(std::vector<T> &a_vector, size_t a_size);

template <typename T>
void oddsOut(std::vector<T> &a_vector, size_t a_size);

template <typename T>
std::pair<size_t, size_t> extremes(std::vector<T> const& a_vector);

template <typename T>
int firstDuplicate(std::vector<T> a_vector);

template <typename T>
std::pair<size_t, size_t> extremes2(std::vector<T> const& a_vector);
}//end of namespace
#include "./inl/linear_algo.hxx"

#endif



// #include <list>

// BEGIN_TEST (data_structures_list)

//     using std::list;

//     std::list<int> numbers;

// ​

//     numbers.push_front(1);

//     numbers.push_front(2);

//     numbers.push_front(3);

// ​

//     numbers.push_back(0);

// ​

//     ASSERT_EQUAL(numbers.size(), 4);

//     ASSERT_EQUAL(numbers.front(), 3);

//     ASSERT_EQUAL(numbers.back(), 0);

//     numbers.pop_front();

//     ASSERT_EQUAL(numbers.front(), 2);

//     list<cpp::Ball> balls;

// ​

// ​

// END_TEST

// ​

// #include <vector>

// BEGIN_TEST (data_structures_vector)

//     using std::vector;

// ​

//     size_t N = 17;

//     vector<int> numbers(N, 42);

//     ASSERT_EQUAL(numbers.size(), 17);

//     ASSERT_EQUAL(numbers.capacity(), N);

//     ASSERT_EQUAL(numbers[0], 42);

//     ASSERT_EQUAL(numbers[1], 42);

// ​

// ​

//     for (size_t i = 0; i < 5; i++)

//     {

//         numbers.push_back(i);

//     }

// ​

//     ASSERT_EQUAL(numbers.size(), N+5);

//     ASSERT_EQUAL(numbers.capacity(), 34);

// ​

//     using cpp::Ball;

//     vector<Ball> balls(12);

//     ASSERT_EQUAL(balls.size(), 12);

//     for (size_t i = 0; i < 10; i++)

//     {

//         balls.push_back(Ball(i, i*i));

//         ASSERT_EQUAL(balls.capacity(), 24);

//     }

//     ASSERT_EQUAL(balls.size(), 22);

// ​

// ​

//     vector<Ball> spaceBalls;

//     const size_t many = 1039;

//     spaceBalls.reserve(many);

// ​

// ​

//     for (size_t i = 0; i < many; i++)

//     {

//         spaceBalls.push_back(Ball(i));

//         ASSERT_EQUAL(spaceBalls.capacity(), 1039);

//         ASSERT_EQUAL(spaceBalls.size(), i+1);

//     }

//     ASSERT_EQUAL(spaceBalls.capacity(), spaceBalls.size());

// ​

//     spaceBalls.push_back(Ball(666));

//     ASSERT_EQUAL(spaceBalls.capacity(), 1039*2);

// ​

//     ASSERT_EQUAL(spaceBalls[0].getRadius(), 0);

//     ASSERT_EQUAL(spaceBalls[3].getRadius(), 3);

// ​

//     spaceBalls[3] = spaceBalls[42];

//     ASSERT_EQUAL(spaceBalls[3].getRadius(), spaceBalls[42].getRadius());

// ​

//     // bug

//     //spaceBalls[ spaceBalls.size() ] = Ball(666);

//     // will fail at runtime

//     //spaceBalls.at( spaceBalls.size()  ) = Ball(666);

// ​

//     for (size_t i = 0; i < many; ++i)

//     {

//         spaceBalls.pop_back();

//     }

//     ASSERT_EQUAL(spaceBalls.size(), 1);

//     ASSERT_EQUAL(spaceBalls.capacity(), 1039*2);

// ​

//     //   [begin, end)

//     vector<Ball> copy(spaceBalls);

//     ASSERT_EQUAL(copy.size(), 1);

//     ASSERT_EQUAL(copy.capacity(), 1);

// ​

//     using std::swap;

//     swap(copy, spaceBalls);

//     ASSERT_EQUAL(spaceBalls.size(), 1);

//     ASSERT_EQUAL(spaceBalls.capacity(), 1);

// ​

// END_TEST

// ​

// #include <map>

// BEGIN_TEST(map_test)

//     using std::map;

// ​

//     map<const char*, int> elements;

//     ASSERT_EQUAL(elements.size(), 0);

// ​

//     int w = elements["iron"];

//     ASSERT_EQUAL(elements.size(), 1);

//     TRACE(w);

// ​

//     elements["ferrum"] = 26;

//     ASSERT_EQUAL(elements.size(), 2);

//     int fe = elements["ferrum"];

//     TRACE(fe);

// ​

//     elements["iron"] = 26;

//     TRACE(elements["iron"]);

//     ++elements["ferrum"];

//     TRACE(elements["ferrum"]);

// ​

//     elements["Aurum"] = 79;

//     TRACE(elements["Aurum"]);

// ​

//     ++elements["x"];

//     TRACE(elements["x"]);

// ​

//     ASSERT_THAT(  elements.find("ferrum") != elements.end() );

// ​

//     ASSERT_THAT(  elements.find("cuprum") == elements.end() );

// ​

//     const char* key = (elements.find("ferrum"))->first;

//     int atomic_weight = (*elements.find("ferrum")).second;

// ​

//     TRACE(key);

//     TRACE(atomic_weight);

// ​

//     TRACE(elements["ferrum"]);

//     ++elements.find("ferrum")->second;

//     TRACE(elements["ferrum"]);

// ​

// ​

// END_TEST

