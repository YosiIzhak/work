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
    sf::RectangleShape frame(sf::Vector2f(shape::level::GAME_BOUND, shape::level::SCREEN_HEIGHT)); 
    sf::SoundBuffer buffer;
    sf::Sound sound;
    shape::game game1;
    shape::level level1;
    shape::collision collision1;
    frame.setFillColor(sf::Color::Transparent);
    frame.setOutlineColor(sf::Color::White);
    frame.setOutlineThickness(2);
    std::vector<shape::ball> balls;
    game1.setBalls(balls);
    std::vector<shape::ball> lives;
    game1.setLiveBalls(lives);

    std::vector<std::unique_ptr<shape::brick> > rectangles;
    //setRectanglesLevel1(rectangles);
    level1.levelBuild(rectangles, 1);
    //std::vector<shape::rectangle> blocks;
    //setBlocksLevel1(blocks);

    std::vector<shape::paddle> paddle;
    game1.setPaddle(paddle);
    sf::Texture texture;
	texture.setRepeated(true);

	texture.loadFromFile("back.jpeg");
    sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, shape::level::GAME_BOUND, shape::level::SCREEN_HEIGHT));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        window.draw(frame);
        window.draw(sprite);

        
        for(auto& f: paddle)
        {
            game1.setPaddlePosition(f); 
            f.drawPaddle(window); 
        }
        
        for(auto& e: lives)
        {
            e.drawBall(window);
        }

        for(auto& e: balls)
        {
            game1.setPosition(e);  
        }

        for(auto& k: rectangles)
        {
            game1.setPositionRect(*k);
            k->drawRectangle(window);  
        }
       
        // for(auto& k: blocks)
        // {
        //     setPositionRect(k);
        //     k.drawRectangle(window);  
        // }

        for(auto& e: balls)
        {
            collision1.checkFall(level1, e, shape::level::SCREEN_WIDTH, shape::level::SCREEN_HEIGHT, lives, buffer, sound, window);
            collision1.changeDirection(e, shape::level::GAME_BOUND, shape::level::SCREEN_HEIGHT, balls);
            collision1.CheckCollision(e, balls);
            e.drawBall(window);
        }

        game1.collisionPaddle(collision1, level1, balls, paddle, window, buffer, sound);
        game1.collisionTreat(collision1,  level1, balls, rectangles, window, buffer, sound);
        game1.changeLevel(level1, rectangles, window);


        window.display();

        usleep(2000);
    }

    return 0;
}