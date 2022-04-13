#include "brick.hpp"

namespace shape
{

brick::brick(sf::Vector2f& a_size, sf::Color a_color, int a_x, int a_y, size_t a_collision)
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

void brick::setXposition(int a_x)
{
    m_x = a_x;
    setPosition();
}

void brick::setYposition(int a_y)
{
    m_y = a_y;
    setPosition();
}
void brick::setOutLine()
{
    m_name.setOutlineThickness(2);
    m_name.setOutlineColor(sf::Color::White);
}

int brick::getCollision() const
{
    return m_collision;
}
void brick::setCollision()
{
    m_collision--;
}

void brick::setPosition()
{
    m_name.setPosition(m_x, m_y);
}

int brick::getXposition()const
{
    return m_x;
}

int brick::getYposition()const
{
    return m_y;
}

void brick::setColor()
{
    m_name.setFillColor(sf::Color::Transparent);
}

size_t brick::getWidth()const
{
    return m_width;
}

size_t brick::getHeight()const
{
    return m_height;
}

void brick::drawRectangle(sf::RenderWindow& a_window)
{
    a_window.draw(m_name);
}

sf::RectangleShape& brick::getRectangleName()
{
   return m_name;
}


void block::setCollision()
{
}



}//namespace shape
