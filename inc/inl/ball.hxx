#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

namespace cpp {


Ball::Ball(char a_color[], int a_value)
: m_color(a_color)
, m_radius(a_value)
{
}

int Ball::getRadius() const
{
  return m_radius;
}


char* Ball::getColor() const
{
  return m_color;
}


}//namespace