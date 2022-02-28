#ifndef PARA_ALGO_HPP
#define PARA_ALGO_HPP

#include <vector>
#include <pthread.h>
#include <cstdlib>

namespace cpp
{

template<typename T>
size_t sumVector(std::vector<T> const& a_vec, size_t a_numOfThreads);


}

#include "./inl/para_algo.hxx"

#endif//PARA_ALGO_HPP