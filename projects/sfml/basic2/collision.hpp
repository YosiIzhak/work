#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <utility>
#include "brick.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "level.hpp"

namespace shape
{

class collision{
public:

void isEqual(shape::ball& a_first, shape::ball& a_second);

void CheckCollision(shape::ball& a_ball, std::vector<shape::ball>& a_balls);

bool intersectPaddle(shape::ball& circle, shape::paddle& paddle);

void changeDirection(shape::ball& a_ball, size_t a_width, size_t a_length, std::vector<shape::ball>& a_balls);

void checkFall(shape::level& a_level, shape::ball& a_ball, size_t a_width, size_t a_length, std::vector<shape::ball>& a_balls, sf::SoundBuffer& a_buffer, sf::Sound& a_sound, sf::RenderWindow& a_window);

bool intersects(shape::ball& circle, shape::brick& rect);
};


}//namespace