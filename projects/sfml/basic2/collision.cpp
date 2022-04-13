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
#include "paddle.hpp"

namespace shape
{
void collision::isEqual(shape::ball& a_first, shape::ball& a_second)
{
    float dx = a_first.getXposition() - a_second.getXposition();
    float dy = a_first.getYposition() - a_second.getYposition();
    float distance = std::sqrt((dx*dx) +(dy*dy));
    if(distance <= a_first.getRadius() + a_second.getRadius())
    {
        a_second.changeXdirection(-1);
        a_second.changeYdirection();
    }
}

void collision::CheckCollision(shape::ball& a_ball, std::vector<shape::ball>& a_balls)
{
    for(auto& e : a_balls)
    {
        if(a_ball == e){}
        else
        {
            isEqual(a_ball, e);
        }
    }
}

bool collision::intersectPaddle(shape::ball& circle, shape::paddle& paddle)
{
    float dist_x = abs(circle.getXposition() - (paddle.getXposition()+ paddle.getWidth() /2));
    float dist_y = abs(circle.getYposition() - (paddle.getYposition() + paddle.getHeight() /2));
    
    if((circle.getXposition() >= paddle.getXposition()) && 
        (circle.getXposition() <= paddle.getXposition() + paddle.getWidth()) &&
        dist_y <= circle.getRadius() + paddle.getHeight()/2)
        {
            return true;
        }
    else if (dist_x <= (paddle.getWidth()/2 + circle.getRadius()) &&
    circle.getYposition() > paddle.getYposition())
    {
         return true; 
    }
    float cornerDis = pow((dist_x),2) + pow((dist_y),2);

    return (cornerDis <= (circle.getRadius()^2));
}

void collision::changeDirection(shape::ball& a_ball, size_t a_width, size_t a_length, std::vector<shape::ball>& a_balls)
{
    if(a_ball.getXposition() >= (int)(a_width - a_ball.getRadius()*2)
    ||
       a_ball.getXposition() <=  0 )
    {
        a_ball.changeXdirection(-1);
    }

    //if(a_ball.getYposition() >= (int)(a_length - a_ball.getRadius()*2)
    //||
      if(a_ball.getYposition() <=  0)
    {
        a_ball.changeYdirection();
    }
} 

void collision::checkFall(shape::level& a_level, shape::ball& a_ball, size_t a_width, size_t a_length, std::vector<shape::ball>& a_balls, sf::SoundBuffer& a_buffer, sf::Sound& a_sound, sf::RenderWindow& a_window)
{
    if(a_ball.getYposition() >= (int)(a_length - a_ball.getRadius()*2))
    {
        usleep(3000);
        a_level.lives(a_balls, a_window);
        a_ball.setXposition(shape::level::GAME_BOUND /2);
        a_ball.setYposition(50);
        a_level.playFallMusic(a_buffer, a_sound);
    }
}

bool collision::intersects(shape::ball& circle, shape::brick& rect)
{
    float dist_x = abs(circle.getXposition() - (rect.getXposition() + rect.getWidth() /2));
    float dist_y = abs(circle.getYposition() - (rect.getYposition() + rect.getHeight() /2));

    if (dist_x > (rect.getWidth()/2 + circle.getRadius())) { return false; }
    if (dist_y > (rect.getHeight()/2 + circle.getRadius())) { return false; }

    if (dist_x <= (rect.getWidth()/2)) { return true; } 
    if (dist_y <= (rect.getHeight()/2)) { return true; }

    float cornerDis = pow((dist_x),2) +
                         pow((dist_y),2);

    return (cornerDis <= (circle.getRadius()^2));
}

}//namespace
