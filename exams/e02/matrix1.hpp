#ifndef MATRIX_H
#define MATRIX_H
#include <cstdlib> 

namespace cpp{

template <typename T>    
class Matrix
{
public:
    Matrix(size_t a_x, size_t a_y);
    Matrix(Matrix const& a_source);
    Matrix& operator=(Matrix const& a_source);
    ~Matrix();
   
    

private:
    T** m_matrix;
    size_t m_x;
    size_t m_y;

};

bool isExist (int** a_matrix,  size_t a_x, size_t a_y, int value);
} // namespace cpp
#endif