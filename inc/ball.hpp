#ifndef BALL_HPP
#define BALL_HPP

#include <cstddef>
#define COLOR_SIZE 10
namespace cpp
{

class Ball
{
public:
    Ball();
    explicit Ball(char a_color[] = "w", int a_radius = 1);
    int getRadius()const;
    void setRadius(int a_radius);
    const char* getColor() const;
    void swap(Ball& a_other);
private:
   char m_color[COLOR_SIZE];
    int m_radius;
};

bool operator<(Ball const& a_first, Ball const& a_second);
void swap(Ball& a_first, Ball& a_second);
} //cpp namespace
#include "./inl/ball.hxx"

#endif /*#ifndefBALL_H122*/


