#ifndef LINEAR_ALGO_HPP
#define LINEAR_ALGO_HPP
#include <cstdlib> //size_t
#include <vector>
#include "utils.hpp"

namespace cpp
{

template <typename T>
void createChaos(std::vector<T> &a_vector, size_t a_size, size_t a_max);

template <typename T>
double sum(std::vector<T> &a_vector, size_t a_size);

template <typename T>
void oddsOut(std::vector<T> &a_vector, size_t a_size);

template <typename T>
std::pair<size_t, size_t> extremes(std::vector<T> const& a_vector);

template <typename T>
size_t firstDuplicate(std::vector<T> const& a_vector);

template <typename T>
std::pair<size_t, size_t> extremes2(std::vector<T> const& a_vector);

template <typename T>
size_t countCommontStrange(std::vector<T> &a_first, std::vector<T> &a_second, std::vector<T> &a_third);

template<typename T>
size_t countCommontStrange2(std::vector<T> const& a_first, std::vector<T> const& a_second, std::vector<T> const& a_third);

template<typename T>
size_t findFirstUnique(std::vector<T> &a_vector);
}//end of namespace
#include "./inl/linear_algo.hxx"

#endif



