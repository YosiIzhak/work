#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <utility>
#include "brick.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "collision.hpp"


namespace shape
{

class game{
public:

void setPosition(shape::ball& a_ball);

void setPaddlePosition(shape::paddle& a_paddle);

void setPositionRect(shape::brick& a_rectangle);

void setBalls(std::vector<shape::ball>& a_balls);

void setPaddle(std::vector<shape::paddle>& a_paddle);

void setLiveBalls(std::vector<shape::ball>& a_lives);

//void setRectanglesLevel1(std::vector<shape::brick>& a_rectangles);

//void setRectanglesLevel2(std::vector<shape::brick>& a_rectangles);

void collisionPaddle(shape::collision& collision1, shape::level& level1, std::vector<shape::ball>& balls, std::vector<shape::paddle>& paddle, sf::RenderWindow& window, sf::SoundBuffer& buffer, sf::Sound& sound);

void collisionTreat(shape::collision& collision1, shape::level& a_level1, std::vector<shape::ball>& a_balls, std::vector<std::unique_ptr<shape::brick> >& rectangles, sf::RenderWindow& a_window, sf::SoundBuffer& a_buffer, sf::Sound& a_sound);

};

}//namespace