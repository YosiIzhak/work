#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <string>
#include <ostream> 
#include <iostream>
#include "matrix1.hpp"

namespace cpp{

template <typename T>
Matrix<T>::Matrix(size_t a_x, size_t a_y)
: m_x(a_x)
, m_y(a_y)
{
   m_matrix = new int*[a_x];
   for(size_t i = 0; i < a_x; ++i)
   {
       m_matrix[a_x] = new int[a_y];
   }
}

template <typename T>
Matrix<T>::Matrix(Matrix<T> const& a_source)
: m_matrix(new int*[a_source.m_matrix])
, m_x(a_source.m_x)
, m_y(a_source.m_y)
{
  for (size_t r = 0; r < a_source.a_x; ++r)
  {
      for (size_t c = 0; c < a_source.a_y; ++c)
      {
          m_matrix[r][c] = a_source.m_matrix[r][c];
      }
  }
}

template <typename T>
Matrix<T>::~Matrix()
{
	for (int r = 0; r < m_x; ++r)
    {
         delete[] m_matrix[r];
    }
    delete[] m_matrix;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T> const& a_source)
{
   for (int r = 0; r < m_x; ++r)
    {
         delete[] m_matrix[r];
    }
    delete[] m_matrix;
    m_matrix = new int*[a_source.m_x];
    for (size_t r = 0; r < a_source.a_x; ++r)
    {
      for (size_t c = 0; c < a_source.a_y; ++c)
      {
          m_matrix[r][c] = a_source.m_matrix[r][c];
      }
    }
    return *this;
}

static bool findcolumn(int** a_matrix, size_t a_x, size_t a_y, int value, size_t line)
{
    int l = 0, r = a_x - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
 
        if (a_matrix[line][mid] == value)
        {
           return true;
        }
 
        if (a_matrix[line][mid] > value)
            r = mid - 1;
        if (a_matrix[line][mid] < value)
            l = mid + 1;
    }
   return false;
}

bool isExist (int** a_matrix,  size_t a_x, size_t a_y, int value)
{
      int l = 0, r = a_y- 1, mid;
 
    while (l <= r)
    {
        mid = (l + r) / 2;
       
        if (value == a_matrix[mid][0]) 
        {
            return true;
        }
 
        if (value == a_matrix[mid][a_x - 1]) 
        {
            return true;
        }
 
        if (value > a_matrix[mid][0] && value < a_matrix[mid][a_x - 1])
        
        {
            findcolumn(a_matrix, a_x, a_y, value, mid);
            
            return;
        }
 
        if (value < a_matrix[mid][0])
            r = mid - 1;
        if (value > a_matrix[mid][a_x - 1])
            l = mid + 1;
    }
}




}// namespace cpp