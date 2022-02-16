#include <cstddef>
#include <algorithm>
#include "ball.hpp"
#include <cstdio>
#include <cstring>
namespace cpp
{

Ball::Ball()
: m_radius(0)
{
    strcpy(m_color,"yellow");
}
Ball::Ball(const char* a_color, int a_radius)
: m_radius(a_radius)
{ 
   strcpy(m_color, a_color); 
}

int Ball::getRadius()const
{
    return m_radius;
}

const char* Ball::getColor() const
{
     return m_color;
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