#include <cstddef>

#include "ball.hpp"

namespace cpp
{


Ball::Ball(char a_color[], int a_radius)
: m_radius(a_radius)
{
	strcpy(m_color,a_color);
}

int Ball::getRadius()const
{
    return m_radius;
}

void Ball::setRadius(int a_radius)
{
    m_radius = a_radius;
}

bool operator==(Ball const& a_first, Ball const& a_second)
{
	return a_first.getRadius() == a_second.getRadius();
}

bool operator!=(Ball const& a_first, Ball const& a_second)
{
	return !(a_first == a_second);
}

bool operator<(Ball const& a_first, Ball const& a_second)
{
    return a_first.getRadius() - a_second.getRadius() < 0;
}

bool operator>(Ball const& a_first, Ball const& a_second)
{
	return !(a_first < a_second);
}

bool operator>=(Ball const& a_first, Ball const& a_second)
{
	return (a_first > a_second) || (a_first == a_second);
}

bool operator<=(Ball const& a_first, Ball const& a_second)
{
	return (a_first < a_second) || (a_first == a_second);
}

} //cpp namespace