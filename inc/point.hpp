#ifndef POINT_HPP
#define POINT_HPP
#include <cstddef> 

namespace cpp {

template <typename T>
class Point
{
public:
    Point(int a_x = 10, int a_y = 10);
    int getX() const;
    int getY() const;
    int distanceFromOrigin() const;

private:
   int m_x;
   int m_y;

};
}// namespace
#include "./inl/point.hxx"

#endif