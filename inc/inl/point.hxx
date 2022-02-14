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
int Point<T>::distanceFromOrigin() const
{
    int calc = pow(m_x, 2) + pow(m_y, 2);
    double distance = sqrt (calc);
    return distance;
}

}//namespace