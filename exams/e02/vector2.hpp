#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib> 
#include <iostream>
#include <vector>

    
class MyVector
{
public:
    MyVector(size_t a_size);
   
   
    int sum (int const& begin, int const& end) const;
    void update(int const& index, int const value);
   

private:
    std::vector<int> m_vector;
    size_t m_size;

};

#endif