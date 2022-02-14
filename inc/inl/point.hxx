#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <math.h>
namespace cpp {

template <typename T>
Point<T>::Point(int a_x, int a_y)
: m_x(a_x)
, m_y(a_y)
{
}

template <typename T>
 int Point<T>::getX() const
 {
     return m_x;
 }
   
   
template <typename T>
int Point<T>::getY() const
{
    return m_y;
}

template <typename T>
void Point<T>::setPoint(T a_x, T a_y)
{
    m_x = a_x;
    m_y = a_y;
}

template <typename T>
int Point<T>::getDistance() const
{
    int calc = pow(m_x, 2) + pow(m_y, 2);
    double distance = sqrt (calc);
    return distance;
}

template <typename T>
void Point<T>::swap(Point<T>& a_other)
{
    using std::swap;
    swap(this->m_x, a_other.m_x);
    swap(this->m_y, a_other.m_y);
}
template <typename T>
bool operator<(Point<T> const& a_first, Point<T> const& a_second)
{
	return (a_first.getDistance() < a_second.getDistance());
}

template <typename T>
void swap(Point<T>& a_first ,Point<T>& a_second)
{
    a_first.swap(a_second);
}

}//namespace