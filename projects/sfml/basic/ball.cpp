#include "ball.hpp"

namespace shape
{

ball::ball(size_t a_radius, sf::Color a_color,  int a_x, int a_y, size_t a_Xspeed, size_t a_Yspeed)
: m_radius(a_radius)
, m_color(a_color)
, m_x(a_x)
, m_y(a_y)
, m_Xdirection(1)
, m_Ydirection(1)
, m_Xspeed(a_Xspeed)
, m_Yspeed(a_Yspeed)
, m_name(m_radius)
{
    m_name.setFillColor(m_color);
    m_name.setPosition(m_x, m_y);
}

void ball::setXposition(int a_x)
{
    m_x = a_x;
    setPosition();
}

void ball::setYposition(int a_y)
{
    m_y = a_y;
    setPosition();
}

void ball::setPosition()
{
    m_name.setPosition(m_x, m_y);
}

void ball::setXSpeed(size_t a_Xspeed)
{
    m_Xspeed = a_Xspeed;
}

void ball::setYSpeed(size_t a_Yspeed)
{
    m_Yspeed = a_Yspeed;
}

void ball::getGlobalBounds()
{
    m_name.getGlobalBounds();
}

void ball::setXdirection(int a_num)
{
    m_Xdirection = a_num;
}

void ball::changeXdirection(int a_num)
{
    m_Xdirection *= a_num;
}

void ball::changeYdirection()
{
    m_Ydirection *= -1;
}

int ball::getXposition()const
{
    return m_x;
}

int ball::getYposition()const
{
    return m_y;
}

size_t ball::getRadius()const
{
    return m_radius;
}

int ball::getXSpeed()const
{
    return m_Xspeed;
}

int ball::getYSpeed()const
{
    return m_Yspeed;
}

int ball::getXdirection()const
{
    return m_Xdirection;
}

int ball::getYdirection()const
{
    return m_Ydirection;
}

void ball::drawBall(sf::RenderWindow& a_window)
{
    a_window.draw(m_name);
}

sf::CircleShape& ball::getBallName()
{
   return m_name;
}

bool ball::operator==(ball const& a_balls)
{
    return (m_x == a_balls.m_x) 
        && (m_y == a_balls.m_y)
        && (m_color == a_balls.m_color) 
        && (m_radius == a_balls.m_radius)
        && (m_Xspeed == a_balls.m_Xspeed)
        && (m_Xdirection == a_balls.m_Xdirection)
        && (m_Ydirection == a_balls.m_Ydirection); 
}

bool ball::compare(ball const& a_balls)
{
    return (m_radius < a_balls.m_radius)
        || (m_x < a_balls.m_x);
}

bool const ball::operator<(ball const& a_balls)
{
    return (m_radius < a_balls.m_radius)
        || (m_x < a_balls.m_x);
}


}//namespace shape



