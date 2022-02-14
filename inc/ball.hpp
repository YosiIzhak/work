#ifndef BALL_HPP
#define BALL_HPP
#include <cstddef> 

namespace cpp {


class Ball
{
public:
    Ball(char a_color[10] = "blue", int a_size = 16);
    // Ball(Ball const& a_source);
    // Ball& operator=(Ball const& a_source);
    // ~Ball();
    int getRadius() const;
    char* getColor() const;

private:
   char*  m_color;
   int m_radius;

};
}// namespace
#include "./inl/ball.hxx"

#endif