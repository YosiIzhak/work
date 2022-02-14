#include <cstddef>
#include <algorithm>
#include "ball.hpp"

namespace cpp
{


Ball::Ball(char a_color, int a_radius)
: m_color(a_color)
, m_radius(a_radius)
{
}

int Ball::getRadius()const
{
    return m_radius;
}

void Ball::setRadius(int a_radius)
{
    m_radius = a_radius;
}

void Ball::swap(Ball& a_other)
{
    using std::swap;
    swap(this->m_color, a_other.m_color);
    swap(this->m_radius, a_other.m_radius);
}

bool operator<(Ball const& a_first, Ball const& a_second)
{
	return (a_first.getRadius() < a_second.getRadius());
}

void swap(Ball& a_first ,Ball& a_second)
{
    a_first.swap(a_second);
}


} //cpp namespace