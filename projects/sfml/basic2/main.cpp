#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <unistd.h>
#include <utility>
#include <cmath>
#include <vector>

#include "paddle.hpp"

#include "level.hpp"
#include "game.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(shape::level::SCREEN_WIDTH, shape::level::SCREEN_HEIGHT), "SFML works!");
    
    shape::game game1;
    
   
    std::vector<shape::paddle> paddle;
    game1.setPaddle(paddle);
   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
               
        for(auto& f: paddle)
        {
            game1.setPaddlePosition(f); 
            f.drawPaddle(window); 
           // std::cout << f.getXposition();
        }
        
        
              

        window.display();

        usleep(4000);
    }

    return 0;
}