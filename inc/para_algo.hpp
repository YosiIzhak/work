#ifndef PARA_ALGO_HPP
#define PARA_ALGO_HPP

#include <vector>
#include <pthread.h>
#include <cstdlib>

namespace cpp
{

template <typename T>
T sumVector(std::vector<T>& a_vec, size_t a_numOfThreads);


} // namespace cpp

#include "./inl/para_algo.hxx"

#endif//PARA_ALGO_HPP