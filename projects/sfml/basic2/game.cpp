#include <iostream>
#include <memory>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <utility>
#include <cmath>
#include "ball.hpp"
#include "brick.hpp"
#include "paddle.hpp"
#include "collision.hpp"
#include "level.hpp"
#include "game.hpp"

namespace shape
{



void game::setPosition(shape::ball& a_ball)
{
    int x =  a_ball.getXposition();
    int y =  a_ball.getYposition();
    x += a_ball.getXdirection()*a_ball.getXSpeed();
    y += a_ball.getYdirection()*a_ball.getYSpeed();
    a_ball.setXposition(x);
    a_ball.setYposition(y);
}

void game::setPaddlePosition(shape::paddle& a_paddle)
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

void game::setPositionRect(shape::brick& a_rectangle)
{
    int x =  a_rectangle.getXposition();
    int y =  a_rectangle.getYposition();
    a_rectangle.setXposition(x);
    a_rectangle.setYposition(y);
}

void game::setBalls(std::vector<shape::ball>& a_balls)
{
    a_balls.push_back(shape::ball(10, sf::Color::Green,shape::level::GAME_BOUND / 2- 20, 50, 1));
   
}

void game::setPaddle(std::vector<shape::paddle>& a_paddle)
{
    sf::Vector2f size1 = {150, 20}; 
    a_paddle.push_back(shape::paddle(size1, sf::Color::Blue, shape::level::GAME_BOUND/ 2 - size1.x /2, shape::level::SCREEN_HEIGHT - 40, 3));
}

void game::setLiveBalls(std::vector<shape::ball>& a_lives)
{
    for(int i = 0; i < 5; ++i)
    {
        a_lives.push_back(shape::ball(10, sf::Color::Green,shape::level::GAME_BOUND +20 + i*40, 40, 1));
    }
    
}
void game::collisionPaddle(shape::collision& collision1, shape::level& level1, std::vector<shape::ball>& balls, std::vector<shape::paddle>& paddle, sf::RenderWindow& window, sf::SoundBuffer& buffer, sf::Sound& sound)
{
   for(auto& e: balls)
        { 
             for(auto& k: paddle)
            {   
                if ( collision1.intersectPaddle(e ,k))
                {
                    e.changeYdirection();
                    if(e.getXposition() < k.getXposition() + k.getWidth() /5)
                    {
                        e.setXdirection(-1);
                        e.setXSpeed(3);
                        e.setYSpeed(2); 
                    }
                    else if (e.getXposition() < k.getXposition() + k.getWidth() *0.4)
                    {
                        e.setXdirection(-1);
                         e.setXSpeed(2);
                         e.setYSpeed(2); 
                    }
                    else if (e.getXposition() < k.getXposition() + k.getWidth() *0.6)
                    {
                        e.setXdirection(0);
                         e.setXSpeed(1);
                         e.setYSpeed(2); 
                    }
                    else if (e.getXposition() < k.getXposition() + k.getWidth() *0.8)
                    {
                        e.setXdirection(1);
                         e.setXSpeed(2);
                         e.setYSpeed(2); 
                    }
                    else 
                    {
                        e.setXdirection(1);
                        e.setXSpeed(3);
                        e.setYSpeed(2); 
                    }

                }
            }
        }
}

void game::collisionTreat(shape::collision& collision1, shape::level& level1, std::vector<shape::ball>& a_balls, std::vector<std::unique_ptr<shape::brick> >& rectangles, sf::RenderWindow& window, sf::SoundBuffer& buffer, sf::Sound& sound)
{
    for(auto& e: a_balls)
        { 
             for(auto& k: rectangles)
            {   
                if ( collision1.intersects(e ,*k))
                {
                    if(k->getCollision() == 5 )
                    {
                        level1.playHitMusic(buffer, sound);
                        e.changeXdirection(-1);
                        e.changeYdirection();
                    }
                    else if(k->getCollision() > 1)
                    {
                        level1.playHitMusic(buffer, sound);
                        e.changeXdirection(-1);
                        e.changeYdirection();
                        k->setCollision();
                    }
                    else if(k->getCollision() == 1)
                    {
                        level1.playBreakMusic(buffer, sound);
                        k->setCollision();
                        k->setColor();
                    }
                    
                }
                if(level1.checkFinishLevel(*k, rectangles))
                {
                    level1.endLevel(window, rectangles);
                    shape::level::LEVEL_NUMBER++;
                    level1.newLevel(shape::level::LEVEL_NUMBER, rectangles);
                    
                }
            }
        }
}

// void setRectanglesLevel1(std::vector<shape::rectangle>& a_rectangles)
// {
//     sf::Vector2f size1 = {40, 20}; 
//     for(int i = 0; i < 2; ++i)
//     {
//         for(int j = 0; j < 2; ++j)
//         {
//            a_rectangles.push_back(shape::rectangle(size1, sf::Color::Blue,shape::level::GAME_BOUND/2-50+10*j+size1.x*j, shape::level::SCREEN_HEIGHT *0.3+10*i+size1.y*i, 1));
//         }
//     a_rectangles.push_back(rectangle(size1, sf::Color::Magenta,shape::level::GAME_BOUND/3+200*i,shape::level::SCREEN_HEIGHT/2+10, 5));
//     }
// }

// void setRectanglesLevel2(std::vector<shape::rectangle>& a_rectangles)
// {
//     sf::Vector2f size1 = {40, 20}; 
//     int count = 0;
//    for(int i = 0; i < 5; ++i)
//     {
//         for(int j = 0; j < 5; ++j)
//         {
//             if (count % 2 == 0)
//             {
//                 a_rectangles.push_back(shape::rectangle(size1, sf::Color::Blue,shape::level::GAME_BOUND/2-2*size1.x +(size1.x+10)*j, shape::level::SCREEN_HEIGHT *0.1+10*i+size1.y*i, 1));
//             }
//             else
//             {
//                 a_rectangles.push_back(shape::rectangle(size1, sf::Color::Red, shape::level::GAME_BOUND/2-2*size1.x+(size1.x+10)*j, shape::level::SCREEN_HEIGHT *0.1+10*i+size1.y*i, 2));
//             }
//         }
//         ++count;
//     }
//     for(int i = 0; i < 3; ++i)
//     {
//         a_rectangles.push_back(rectangle(size1, sf::Color::Magenta,shape::level::GAME_BOUND*(0.2 +0.35*i) ,shape::level::SCREEN_HEIGHT/2+10, 5));
//     }
// }



}//namespace

