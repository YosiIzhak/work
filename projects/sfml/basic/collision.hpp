#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <utility>

namespace shape
{
void isEqual(shape::ball& a_first, shape::ball& a_second);

void CheckCollision(shape::ball& a_ball, std::vector<shape::ball>& a_balls);

bool intersectPaddle(shape::ball& circle, shape::paddle& paddle);

void changeDirection(shape::ball& a_ball, size_t a_width, size_t a_length, std::vector<shape::ball>& a_balls);

void checkFall(shape::ball& a_ball, size_t a_width, size_t a_length, std::vector<shape::ball>& a_balls, sf::RenderWindow& a_window);




}//namespace