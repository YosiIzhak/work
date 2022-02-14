#ifndef POINT_HPP
#define POINT_HPP
#include <cstddef> 

namespace cpp {

template <typename T>
class Point
{
public:
    Point(int a_x = 10, int a_y = 10);
    void setPoint(T a_x, T a_y);
    int getX() const;
    int getY() const;
    int getDistance() const;

private:
   int m_x;
   int m_y;

};

template <typename T>
bool operator==(Point<T> const& a_first, Point<T> const& a_second);
template <typename T>
bool operator!=(Point<T> const& a_first, Point<T> const& a_second);
template <typename T>
bool operator<(Point<T> const& a_first, Point<T> const& a_second);
template <typename T>
bool operator>(Point<T> const& a_first, Point<T> const& a_second);
template <typename T>
bool operator>=(Point<T> const& a_first, Point<T> const& a_second);
template <typename T>
bool operator<=(Point<T> const& a_first, Point<T> const& a_second);
}// namespace
#include "./inl/point.hxx"

#endif