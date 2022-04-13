#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <utility>
#include "brick.hpp"
#include "ball.hpp"

using namespace sf;
namespace shape
{

class level{
public:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    static int GAME_BOUND;
    static int LEVEL_NUMBER;
 

   bool checkFinishLevel(shape::brick& a_rect, std::vector<std::unique_ptr<shape::brick> >& a_rectangles);
    
    void lives(std::vector<shape::ball>& a_balls, sf::RenderWindow& a_window);

    void newLevel(int level_num, std::vector<std::unique_ptr<shape::brick> >& rectangles);

    void endLevel(sf::RenderWindow& a_window, std::vector<std::unique_ptr<shape::brick> >& a_rectangles);

    void playHitMusic(sf::SoundBuffer& a_buffer, sf::Sound& a_sound);

    void playBreakMusic(sf::SoundBuffer& a_buffer, sf::Sound& a_sound);

    void playFallMusic(sf::SoundBuffer& a_buffer, sf::Sound& a_sound);

    void levelBuild (std::vector<std::unique_ptr<shape::brick> >& a_rectangles, int level);

   
    Color intToColor(std::string& a_color);

    

};

}//namespace