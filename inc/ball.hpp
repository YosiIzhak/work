#ifndef BALL_HPP
#define BALL_HPP

#include <cstddef>

namespace cpp
{

class Ball
{
public:
    explicit Ball(char a_color = 'A', int a_radius = 1); //to fix
    int getRadius()const;
    void setRadius(int a_radius);
    char getColor()const;
    void setColor(char a_color);
    void swap(Ball& a_other);
private:
    char m_color;
    int m_radius;
};

bool operator<(Ball const& a_first, Ball const& a_second);
void swap(Ball& a_first, Ball& a_second);
} //cpp namespace


#endif /*#ifndefBALL_H122*/