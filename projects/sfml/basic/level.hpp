#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <utility>

namespace shape
{
bool checkFinishLevel(shape::rectangle& a_rect, std::vector<shape::rectangle>& a_rectangles);


void lives(std::vector<shape::ball>& a_balls);


}//namespace