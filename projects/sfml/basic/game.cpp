#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <utility>
#include <cmath>
#include "ball.hpp"
#include "rectangle.hpp"
#include "paddle.hpp"
#include "collision.hpp"
#include "level.hpp"
#include "game.hpp"

namespace shape
{


void setPosition(shape::ball& a_ball)
{
    int x =  a_ball.getXposition();
    int y =  a_ball.getYposition();
    x += a_ball.getXdirection()*a_ball.getXSpeed();
    y += a_ball.getYdirection()*a_ball.getYSpeed();
    a_ball.setXposition(x);
    a_ball.setYposition(y);
}

void setPaddlePosition(shape::paddle& a_paddle)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
       a_paddle.setXdirection(-1);
       int x =  a_paddle.getXposition();
       if (x > 0)
       {
          x += a_paddle.getXdirection()*a_paddle.getSpeed();
          a_paddle.setXposition(x);
       }
       
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {   
       a_paddle.setXdirection(1);
       int x =  a_paddle.getXposition();
       if (x < shape::level::GAME_BOUND - a_paddle.getWidth())
       x += a_paddle.getXdirection()*a_paddle.getSpeed();
       a_paddle.setXposition(x);
    }
}

void setPositionRect(shape::rectangle& a_rectangle)
{
    int x =  a_rectangle.getXposition();
    int y =  a_rectangle.getYposition();
    a_rectangle.setXposition(x);
    a_rectangle.setYposition(y);
}

void setBalls(std::vector<shape::ball>& a_balls)
{
    //a_balls.push_back(shape::ball(15, sf::Color::Blue,100, 0, 2));
    //a_balls.push_back(shape::ball(20, sf::Color::Red,0, 50));
    a_balls.push_back(shape::ball(10, sf::Color::Green,shape::level::GAME_BOUND / 2- 20, 50, 1));
    // a_balls.push_back(shape::ball(20, sf::Color::Yellow,0, 300));
    // a_balls.push_back(shape::ball(20, sf::Color::Cyan,300, 0, 2));
    // a_balls.push_back(shape::ball(15, sf::Color::Magenta ,0, 450));
    // a_balls.push_back(shape::ball(15, sf::Color::White,400, 0));
}

void setLiveBalls(std::vector<shape::ball>& a_lives)
{
    for(int i = 0; i < 5; ++i)
    {
        a_lives.push_back(shape::ball(10, sf::Color::Green,shape::level::GAME_BOUND +20 + i*40, 40, 1));
    }
    
}

void setRectanglesLevel1(std::vector<shape::rectangle>& a_rectangles)
{
    sf::Vector2f size1 = {40, 20}; 
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
           a_rectangles.push_back(shape::rectangle(size1, sf::Color::Blue,shape::level::GAME_BOUND/2-50+10*j+size1.x*j, shape::level::SCREEN_HEIGHT *0.3+10*i+size1.y*i, 1));
        }
    a_rectangles.push_back(rectangle(size1, sf::Color::Magenta,shape::level::GAME_BOUND/3+220*i,shape::level::SCREEN_HEIGHT/2+10, 5));
    }
}

// void setBlocksLevel1(std::vector<shape::rectangle>& a_blocks)
// {
//     sf::Vector2f size1 = {40, 20}; 
//     for(int j = 0; j < 3; ++j)
//     {
//       a_blocks.push_back(rectangle(size1, sf::Color::Magenta,shape::level::GAME_BOUND*(0.15 +0.3*j) ,shape::level::SCREEN_HEIGHT/2, 5));
//     }
// }

void setRectanglesLevel2(std::vector<shape::rectangle>& a_rectangles)
{
    sf::Vector2f size1 = {40, 20}; 
    int count = 0;
   for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if (count % 2 == 0)
            {
                a_rectangles.push_back(shape::rectangle(size1, sf::Color::Blue,shape::level::GAME_BOUND/2-2*size1.x +(size1.x+10)*j, shape::level::SCREEN_HEIGHT *0.1+10*i+size1.y*i, 1));
            }
            else
            {
                a_rectangles.push_back(shape::rectangle(size1, sf::Color::Red, shape::level::GAME_BOUND/2-2*size1.x+(size1.x+10)*j, shape::level::SCREEN_HEIGHT *0.1+10*i+size1.y*i, 2));
            }
        }
        ++count;
    }
    for(int i = 0; i < 3; ++i)
    {
        a_rectangles.push_back(rectangle(size1, sf::Color::Magenta,shape::level::GAME_BOUND*(0.1 +0.4*i) ,shape::level::SCREEN_HEIGHT/2+10, 5));
    }
}

}//namespace