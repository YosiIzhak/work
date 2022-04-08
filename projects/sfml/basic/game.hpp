#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <utility>



namespace shape
{

void setPosition(shape::ball& a_ball);

void setPaddlePosition(shape::paddle& a_paddle);

void setPositionRect(shape::rectangle& a_rectangle);

void setBalls(std::vector<shape::ball>& a_balls);
 
void setLiveBalls(std::vector<shape::ball>& a_lives);

//void setBlocksLevel1(std::vector<shape::block>& a_blocks);

void setRectanglesLevel1(std::vector<shape::rectangle>& a_rectangles);

void setRectanglesLevel2(std::vector<shape::rectangle>& a_rectangles);

}//namespace