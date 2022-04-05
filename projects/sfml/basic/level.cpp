#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <utility>
#include <cmath>
#include "ball.hpp"
#include "rectangle.hpp"
#include "paddle.hpp"
#include "collision.hpp"

namespace shape
{
bool checkFinishLevel(shape::rectangle& a_rect, std::vector<shape::rectangle>& a_rectangles)
{
    for(auto& k: a_rectangles)
    {
        if(k.getCollision() != 0)
        {
            return false; 
        }
    }
    return true;
}

void lives(std::vector<shape::ball>& a_balls)
{
    if (a_balls.size() > 0)
    {
        a_balls.pop_back();
    }
        
}


}//namespace