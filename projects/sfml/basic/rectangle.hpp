#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <utility>


namespace shape
{

class rectangle
{
public:
    rectangle(sf::Vector2f& a_size, sf::Color a_color,  int a_x = 0, int a_y = 0, size_t a_id = 0);
    void setXposition(int a_x);
    void setYposition(int a_y);
    int getCollision() const;
    void setCollision();
    int getXposition()const;
    int getYposition()const;
    void setColor();
    void setOutLine();
    size_t getWidth()const;
    size_t getHeight()const;
    void drawRectangle(sf::RenderWindow& a_window);
    sf::RectangleShape& getRectangleName();

    bool operator==(rectangle const& a_rectangle);
    // bool compare(Rectangle const& a_rectangle);
    // bool const operator<(Rectangle const& a_rectangle);

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


// inline bool operator<(Rectangle& a_first, Rectangle const& a_second)
// {
//     return a_first.compare(a_second);
// }


}//namespace shape

// class block : public rectangle 
// {
// public:    
//    block(sf::Vector2f& a_size, sf::Color a_color,  int a_x = 0, int a_y = 0, size_t a_id = 5)
//    : rectangle(a_size, a_color, a_x, a_y, a_id)
//    {
      
//    }
    
//     void setCollision();
// };



