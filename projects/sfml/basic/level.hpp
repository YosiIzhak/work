#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <utility>

namespace shape
{

class level{
public:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    static int GAME_BOUND;
    static int LEVEL_NUMBER;
 

};

    bool checkFinishLevel(shape::rectangle& a_rect, std::vector<shape::rectangle>& a_rectangles);
    
    void lives(std::vector<shape::ball>& a_balls, sf::RenderWindow& a_window);

    void newLevel(int level_num, std::vector<shape::rectangle>& rectangles);

    void endLevel(sf::RenderWindow& a_window);

    void playHitMusic(sf::SoundBuffer& a_buffer, sf::Sound& a_sound);

    void playBreakMusic(sf::SoundBuffer& a_buffer, sf::Sound& a_sound);

    //void playFallMusic(sf::SoundBuffer& a_buffer, sf::Sound& a_sound);

}//namespace