#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <utility>
#include <cmath>
#include "ball.hpp"
#include "rectangle.hpp"
#include "paddle.hpp"
#include "collision.hpp"
#include "level.hpp"
#include "game.hpp"





void setPaddle(std::vector<shape::paddle>& a_paddle)
{
    sf::Vector2f size1 = {150, 20}; 
    a_paddle.push_back(shape::paddle(size1, sf::Color::Blue, shape::level::GAME_BOUND/ 2 - size1.x /2, shape::level::SCREEN_HEIGHT - 40, 1));
}

bool intersects(shape::ball& circle, shape::rectangle& rect)
{
    float dist_x = abs(circle.getXposition() - (rect.getXposition() + rect.getWidth() /2));
    float dist_y = abs(circle.getYposition() - (rect.getYposition() + rect.getHeight() /2));

    if (dist_x > (rect.getWidth()/2 + circle.getRadius())) { return false; }
    if (dist_y > (rect.getHeight()/2 + circle.getRadius())) { return false; }

    if (dist_x <= (rect.getWidth()/2)) { return true; } 
    if (dist_y <= (rect.getHeight()/2)) { return true; }

    float cornerDis = pow((dist_x),2) +
                         pow((dist_y),2);

    return (cornerDis <= (circle.getRadius()^2));
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(shape::level::SCREEN_WIDTH, shape::level::SCREEN_HEIGHT), "SFML works!");
    sf::RectangleShape frame(sf::Vector2f(shape::level::GAME_BOUND, shape::level::SCREEN_HEIGHT)); 
    sf::SoundBuffer buffer;
    sf::Sound sound;
    frame.setFillColor(sf::Color::Transparent);
    frame.setOutlineColor(sf::Color::White);
    frame.setOutlineThickness(2);
    std::vector<shape::ball> balls;
    setBalls(balls);
    std::vector<shape::ball> lives;
    setLiveBalls(lives);

    std::vector<shape::rectangle> rectangles;
    setRectanglesLevel2(rectangles);
   
    //std::vector<shape::block> blocks;
    //setBlocksLevel1(blocks);

    std::vector<shape::paddle> paddle;
    setPaddle(paddle);
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
            setPaddlePosition(f); 
            f.drawPaddle(window); 
        }
        
        for(auto& e: lives)
        {
            e.drawBall(window);
        }

        for(auto& e: balls)
        {
            setPosition(e);  
        }

        for(auto& k: rectangles)
        {
            setPositionRect(k);
            k.drawRectangle(window);  
        }
       
        // for(auto& k: blocks)
        // {
        //     setPositionRect(k);
        //     k.drawRectangle(window);  
        // }

        for(auto& e: balls)
        {
            checkFall(e, shape::level::SCREEN_WIDTH, shape::level::SCREEN_HEIGHT, lives, window);
            changeDirection(e, shape::level::GAME_BOUND, shape::level::SCREEN_HEIGHT, balls);
            CheckCollision(e, balls);
            e.drawBall(window);
        }

        for(auto& e: balls)
        { 
             for(auto& k: rectangles)
            {   
                if ( intersects(e ,k))
                {
                    if(k.getCollision() > 1)
                    {
                        shape::playHitMusic(buffer, sound);
                        e.changeXdirection(-1);
                        e.changeYdirection();
                        k.setCollision();
                    }
                    else if(k.getCollision() == 1)
                    {
                        shape::playBreakMusic(buffer, sound);
                        k.setCollision();
                        k.setColor();
                    }
                    
                }
                if(checkFinishLevel(k, rectangles))
                {
                    shape::endLevel(window);
                    shape::level::LEVEL_NUMBER++;
                    shape::newLevel(shape::level::LEVEL_NUMBER, rectangles);
                    
                }
            }
        }

        for(auto& e: balls)
        { 
             for(auto& k: paddle)
            {   
                if ( intersectPaddle(e ,k))
                {
                    e.changeYdirection();
                    if(e.getXposition() < k.getXposition() + k.getWidth() /5)
                    {
                        e.setXdirection(-1);
                        e.setXSpeed(2);
                        e.setYSpeed(1); 
                    }
                    else if (e.getXposition() < k.getXposition() + k.getWidth() *0.4)
                    {
                        e.setXdirection(-1);
                         e.setXSpeed(1);
                         e.setYSpeed(1); 
                    }
                    else if (e.getXposition() < k.getXposition() + k.getWidth() *0.6)
                    {
                        e.setXdirection(0);
                         e.setXSpeed(1);
                         e.setYSpeed(2); 
                    }
                    else if (e.getXposition() < k.getXposition() + k.getWidth() *0.8)
                    {
                        e.setXdirection(1);
                         e.setXSpeed(1);
                         e.setYSpeed(1); 
                    }
                    else 
                    {
                        e.setXdirection(1);
                        e.setXSpeed(2);
                        e.setYSpeed(1); 
                    }

                }
            }
        }

        window.display();

        usleep(3000);
    }

    return 0;
}