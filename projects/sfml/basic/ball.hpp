#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <utility>


namespace shape
{

class ball
{
public:
    ball(size_t a_radius, sf::Color a_color,  int a_x = 0, int a_y = 0, size_t a_Xspeed = 1, size_t a_Yspeed = 1);
    void setXposition(int a_x);
    void setYposition(int a_y);
    void setXSpeed(size_t a_Xspeed);
    void setYSpeed(size_t a_Yspeed);
    void setXdirection(int a_num);
    void changeXdirection(int a_num);
    void changeYdirection();
    void getGlobalBounds();
    int getXposition()const;
    int getYposition()const;
    int getXdirection()const;
    int getYdirection()const;
    size_t getRadius()const;
    int getXSpeed()const;
    int getYSpeed()const;

    void drawBall(sf::RenderWindow& a_window);
    sf::CircleShape& getBallName();

    bool operator==(ball const& a_balls);
    bool compare(ball const& a_balls);
    bool const operator<(ball const& a_balls);

private:
    void setPosition();

private:
    size_t m_radius;
    sf::Color m_color;
    int m_x;
    int m_y;
    int m_Xdirection;
    int m_Ydirection;
    size_t m_Xspeed;
    size_t m_Yspeed;
    sf::CircleShape m_name;
};


inline bool operator<(ball& a_first, ball const& a_second)
{
    return a_first.compare(a_second);
}


}//namespace shape