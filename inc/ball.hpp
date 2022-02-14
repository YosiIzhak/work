#ifndef BALL_HPP
#define BALL_HPP

#include <cstddef>

namespace cpp
{

class Ball
{
public:
    Ball(char a_color = 'A', int a_radius = 1);
    int getRadius()const;
    void setRadius(int a_radius);

private:
    char m_color;
    int m_radius;
};

bool operator==(Ball const& a_first, Ball const& a_second);
bool operator!=(Ball const& a_first, Ball const& a_second);
bool operator<(Ball const& a_first, Ball const& a_second);
bool operator>(Ball const& a_first, Ball const& a_second);
bool operator>=(Ball const& a_first, Ball const& a_second);
bool operator<=(Ball const& a_first, Ball const& a_second);

} //cpp namespace


#endif /*#ifndefBALL_H122*/