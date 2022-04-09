#include "rectangle.hpp"

namespace shape
{

rectangle::rectangle(sf::Vector2f& a_size, sf::Color a_color, int a_x, int a_y, size_t a_collision)
: m_width(a_size.x)
, m_height(a_size.y)
, m_color(a_color)
, m_x(a_x)
, m_y(a_y)
, m_collision(a_collision)
, m_name(a_size)
{
    m_name.setFillColor(m_color);
    m_name.setPosition(m_x, m_y);
}

void rectangle::setXposition(int a_x)
{
    m_x = a_x;
    setPosition();
}

void rectangle::setYposition(int a_y)
{
    m_y = a_y;
    setPosition();
}
void rectangle::setOutLine()
{
    m_name.setOutlineThickness(2);
    m_name.setOutlineColor(sf::Color::White);
}

int rectangle::getCollision() const
{
    return m_collision;
}
void rectangle::setCollision()
{
    m_collision--;
}

void rectangle::setPosition()
{
    m_name.setPosition(m_x, m_y);
}

int rectangle::getXposition()const
{
    return m_x;
}

int rectangle::getYposition()const
{
    return m_y;
}

void rectangle::setColor()
{
    m_name.setFillColor(sf::Color::Transparent);
}

size_t rectangle::getWidth()const
{
    return m_width;
}

size_t rectangle::getHeight()const
{
    return m_height;
}

void rectangle::drawRectangle(sf::RenderWindow& a_window)
{
    a_window.draw(m_name);
}

sf::RectangleShape& rectangle::getRectangleName()
{
   return m_name;
}

bool rectangle::operator==(rectangle const& a_rectangle)
{
    return (m_x == a_rectangle.m_x) 
        && (m_y == a_rectangle.m_y)
        && (m_width == a_rectangle.m_width)
        && (m_height == a_rectangle.m_height)
        && (m_color == a_rectangle.m_color);       
}

// bool Rectangle::compare(Rectangle const& a_rectangle)
// {
//     return (m_radius < a_balls.m_radius)
//         || (m_x < a_balls.m_x);
// }

// bool const Rectangle::operator<(Rectangle const& a_balls)
// {
//     return (m_radius < a_balls.m_radius)
//         || (m_x < a_balls.m_x);
// }


}//namespace shape
