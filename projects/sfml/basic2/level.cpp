#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <fstream>
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

using namespace sf;


int level::SCREEN_WIDTH = 1000;
int level::SCREEN_HEIGHT = 400;
int level::GAME_BOUND = 750;
int level::LEVEL_NUMBER = 1;

void level::playHitMusic(sf::SoundBuffer& a_buffer, sf::Sound& a_sound)
{
   a_buffer.loadFromFile("hit.wav");
   a_sound.setBuffer(a_buffer);
   a_sound.play();
}

void level::playBreakMusic(sf::SoundBuffer& a_buffer, sf::Sound& a_sound)
{
   a_buffer.loadFromFile("break.wav");
   a_sound.setBuffer(a_buffer);
   a_sound.play();
}

void level::playFallMusic(sf::SoundBuffer& a_buffer, sf::Sound& a_sound)
{
   a_buffer.loadFromFile("fall.wav");
   a_sound.setBuffer(a_buffer);
   a_sound.play();
}

bool level::checkFinishLevel(shape::brick& a_rect, std::vector<std::unique_ptr<shape::brick> >& a_rectangles)
{
    for(auto& k: a_rectangles)
    {
        if(k->getCollision() != 0 && k->getCollision() != 5)
        {
            return false; 
        }
    }
    return true;
}

void level::lives(std::vector<shape::ball>& a_balls, sf::RenderWindow& a_window)
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

void level::endLevel(sf::RenderWindow& a_window, std::vector<std::unique_ptr<shape::brick> >& a_rectangles)
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

void level::newLevel(int level_num, std::vector<std::unique_ptr<shape::brick> >& rectangles)
{
   
        //setRectanglesLevel1(rectangles);
        levelBuild(rectangles, level_num);
    
    // else if(level_num == 2)
    // {
    //     //setRectanglesLevel2(rectangles);
    //     levelBuild2(rectangles);
    // }
    // else if(level_num == 3)
    // {
    //     //setRectanglesLevel2(rectangles);
    //     levelBuild2(rectangles);
    // }
}

Color level::intToColor(std::string& a_color) 
{
    static Color lut[] = 
    {
        Color::Black, 
        Color::White, 
        Color::Red, 
        Color::Green, 
        Color::Blue, 
        Color::Yellow, 
        Color::Magenta,
        Color::Cyan,
        Color::Transparent
    };

    int color = stoi(a_color);
    if( 0 <= color &&  color <= 9)
    {
        return lut[color];
    }
    return Color::Yellow;
}


void level::levelBuild (std::vector<std::unique_ptr<shape::brick> >& a_rectangles, int a_level)
{
    std::ifstream file ("level" +std::to_string(a_level) + ".txt");
    sf::Vector2f size;
    Color color;
    
    int x, y, w, h;
    std::string c;
    size_t type;
    while(file.good())
    {
        file >> x >> y >> c >> w >> h >> type;
        if (file.good())
        {
            //std::cout << x << y << c << w << h << type << std::endl;
            size.x = x;
            size.y = y;
            std::string numOfColor = c;
            Color color = intToColor(numOfColor);
         
          if (type)
          {
            a_rectangles.push_back(std::unique_ptr<shape::brick>(new shape::brick(size, color, w, h, type)));
          }
          else
          {
            a_rectangles.push_back(std::unique_ptr<shape::brick>(new shape::block(size, color, w, h, type)));
          }
        }
    }
}


}//namespace