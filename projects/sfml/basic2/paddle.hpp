#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <utility>


namespace shape
{

class paddle
{
public:
    paddle(sf::Vector2f& a_size, sf::Color a_color,  int a_x = 0, int a_y = 0, size_t a_speed = 0);
    void setXposition(int a_x);
    void setYposition(int a_y);
    void setXdirection(int a_dir);
    int getXdirection()const;
    int getXposition()const;
    int getYposition()const;
    void setSpeed(size_t a_speed);
    int getWidth()const;
    size_t getHeight()const;
    int getSpeed()const;
    void drawPaddle(sf::RenderWindow& a_window);
    sf::RectangleShape& getRectangleName();

    bool operator==(paddle const& a_paddle);
    
private:
    void setPosition();

private:
    size_t m_width;
    size_t m_height;
    sf::Color m_color;
    int m_Xdirection;
    int m_x;
    int m_y;
    size_t m_speed;
    sf::RectangleShape m_name;
};


}//namespace