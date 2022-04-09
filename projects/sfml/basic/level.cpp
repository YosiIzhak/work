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

int level::SCREEN_WIDTH = 1000;
int level::SCREEN_HEIGHT = 400;
int level::GAME_BOUND = 750;
int level::LEVEL_NUMBER = 1;

void playHitMusic(sf::SoundBuffer& a_buffer, sf::Sound& a_sound)
{
   a_buffer.loadFromFile("hit.wav");
   a_sound.setBuffer(a_buffer);
   a_sound.play();
}

void playBreakMusic(sf::SoundBuffer& a_buffer, sf::Sound& a_sound)
{
   a_buffer.loadFromFile("break.wav");
   a_sound.setBuffer(a_buffer);
   a_sound.play();
}

void playFallMusic(sf::SoundBuffer& a_buffer, sf::Sound& a_sound)
{
   a_buffer.loadFromFile("fall.wav");
   a_sound.setBuffer(a_buffer);
   a_sound.play();
}

bool checkFinishLevel(shape::rectangle& a_rect, std::vector<shape::rectangle>& a_rectangles)
{
    for(auto& k: a_rectangles)
    {
        if(k.getCollision() != 0 && k.getCollision() != 5)
        {
            return false; 
        }
    }
    return true;
}

void lives(std::vector<shape::ball>& a_balls, sf::RenderWindow& a_window)
{
    if (a_balls.size() > 0)
    {
        a_balls.pop_back();
    }
    else
    {
        a_window.clear();
        sf::Texture texture;
        texture.setRepeated(true);
        texture.loadFromFile("over.jpeg");
 
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, shape::level::SCREEN_WIDTH, shape::level::SCREEN_HEIGHT));
        a_window.draw(sprite);
        a_window.display();
        sleep(2);
        a_window.close();
    }
}

void endLevel(sf::RenderWindow& a_window, std::vector<shape::rectangle>& a_rectangles)
{
    a_window.clear();
    a_rectangles.clear();
    sf::Texture texture;
    texture.setRepeated(true);
    texture.loadFromFile("prize.jpeg");
 
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, shape::level::SCREEN_WIDTH, shape::level::SCREEN_HEIGHT));
    
    a_window.draw(sprite);
    a_window.display();
    sleep(2);
   
}

void newLevel(int level_num, std::vector<shape::rectangle>& rectangles)
{
    if (level_num == 1)
    {
        setRectanglesLevel1(rectangles);
    }
    else if(level_num == 2)
    {
        setRectanglesLevel2(rectangles);
    }
}



}//namespace