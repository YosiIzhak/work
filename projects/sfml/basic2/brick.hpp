#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <utility>


namespace shape
{

class brick
{
public:
    brick(sf::Vector2f& a_size, sf::Color a_color,  int a_x = 0, int a_y = 0, size_t a_id = 0);
    void setXposition(int a_x);
    void setYposition(int a_y);
    int getCollision() const;
    virtual void setCollision();
    int getXposition()const;
    int getYposition()const;
    void setColor();
    void setOutLine();
    size_t getWidth()const;
    size_t getHeight()const;
    void drawRectangle(sf::RenderWindow& a_window);
    sf::RectangleShape& getRectangleName();

private:
    void setPosition();


private:
    size_t m_width;
    size_t m_height;
    sf::Color m_color;
    int m_x;
    int m_y;
    size_t m_collision;
    sf::RectangleShape m_name;
};

class block : public brick 
{
public:    
   block(sf::Vector2f& a_size, sf::Color a_color,  int a_x = 0, int a_y = 0, size_t a_id = 5)
   : brick(a_size, a_color, a_x, a_y, a_id)
   {
      
   }
    
    virtual void setCollision();
};

}//namespace shape
