#include "paddle.hpp"

namespace shape
{

paddle::paddle(sf::Vector2f& a_size, sf::Color a_color, int a_x, int a_y, size_t a_speed)
: m_width(a_size.x)
, m_height(a_size.y)
, m_color(a_color)
, m_x(a_x)
, m_y(a_y)
, m_name(a_size)
{
    m_name.setFillColor(m_color);
    m_name.setPosition(m_x, m_y);
}

void paddle::setXdirection(int a_direction)
{
    m_Xdirection = a_direction;
}

int paddle::getXdirection()const
{
    return m_Xdirection;
}

void paddle::setXposition(int a_x)
{
    m_x = a_x;
    setPosition();
}

void paddle::setYposition(int a_y)
{
    m_y = a_y;
    setPosition();
}

void paddle::setPosition()
{
    m_name.setPosition(m_x, m_y);
}

int paddle::getXposition()const
{
    return m_x;
}

int paddle::getYposition()const
{
    return m_y;
}

int paddle::getWidth()const
{
    return m_width;
}

size_t paddle::getHeight()const
{
    return m_height;
}

int paddle::getSpeed()const
{
    return m_speed;
}
void paddle::drawPaddle(sf::RenderWindow& a_window)
{
    a_window.draw(m_name);
}

sf::RectangleShape& paddle::getRectangleName()
{
   return m_name;
}

bool paddle::operator==(paddle const& a_rectangle)
{
    return (m_x == a_rectangle.m_x) 
        && (m_y == a_rectangle.m_y)
        && (m_width == a_rectangle.m_width)
        && (m_height == a_rectangle.m_height)
        && (m_color == a_rectangle.m_color);       
}


}//namespace shape



