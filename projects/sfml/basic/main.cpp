#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <utility>
#include <cmath>
#include "ball.hpp"
#include "rectangle.hpp"
#include "paddle.hpp"
#include "collision.hpp"
#include "level.hpp"

int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 400;
int GAME_BOUND = SCREEN_WIDTH * 0.75;

//void isEqual(shape::ball& a_first, shape::ball& a_second);

   



void setPosition(shape::ball& a_ball)
{
    int x =  a_ball.getXposition();
    int y =  a_ball.getYposition();
    x += a_ball.getXdirection()*a_ball.getSpeed();
    y += a_ball.getYdirection()*a_ball.getSpeed();
    a_ball.setXposition(x);
    a_ball.setYposition(y);
}

void setPaddlePosition(shape::paddle& a_paddle)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
       a_paddle.setXdirection(-1);
       int x =  a_paddle.getXposition();
       if (x > 0)
       {
          x += a_paddle.getXdirection()*a_paddle.getSpeed();
          a_paddle.setXposition(x);
       }
       
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {   
        a_paddle.setXdirection(1);
       int x =  a_paddle.getXposition();
       if (x < GAME_BOUND - a_paddle.getWidth())
       x += a_paddle.getXdirection()*a_paddle.getSpeed();
       a_paddle.setXposition(x);
    }
}

void setPositionRect(shape::rectangle& a_rectangle)
{
    int x =  a_rectangle.getXposition();
    int y =  a_rectangle.getYposition();
    a_rectangle.setXposition(x);
    a_rectangle.setYposition(y);
}





void setBalls(std::vector<shape::ball>& a_balls)
{
    //a_balls.push_back(shape::ball(15, sf::Color::Blue,100, 0, 2));
    //a_balls.push_back(shape::ball(20, sf::Color::Red,0, 50));
    a_balls.push_back(shape::ball(10, sf::Color::Green,GAME_BOUND / 2- 20, SCREEN_HEIGHT /2 +5, 1));
    // a_balls.push_back(shape::ball(20, sf::Color::Yellow,0, 300));
    // a_balls.push_back(shape::ball(20, sf::Color::Cyan,300, 0, 2));
    // a_balls.push_back(shape::ball(15, sf::Color::Magenta ,0, 450));
    // a_balls.push_back(shape::ball(15, sf::Color::White,400, 0));
}

void setLiveBalls(std::vector<shape::ball>& a_lives)
{
    for(int i = 0; i < 5; ++i)
    {
        a_lives.push_back(shape::ball(10, sf::Color::Green,GAME_BOUND +20 + i*40, 40, 1));
    }
    
}
void setRectangles(std::vector<shape::rectangle>& a_rectangles)
{
    sf::Vector2f size1 = {40, 20}; 
    int count = 0;
    for(int i = size1.y; i < SCREEN_HEIGHT /2; i = i+ size1.y* 1.5)
    {
        for(int j = size1.x; j < GAME_BOUND - size1.x; j = j + size1.x + 10)
        {
            if (count % 2 == 0)
            {
                a_rectangles.push_back(shape::rectangle(size1, sf::Color::Blue,j, i, 1));
            }
            else
            {
                a_rectangles.push_back(shape::rectangle(size1, sf::Color::Red, j, i, 2));
            }
        }
        ++count;
    }
}

void setPaddle(std::vector<shape::paddle>& a_paddle)
{
    sf::Vector2f size1 = {150, 20}; 
    a_paddle.push_back(shape::paddle(size1, sf::Color::Blue,GAME_BOUND / 2 - size1.x /2, SCREEN_HEIGHT - 40, 1));
}

bool intersects(shape::ball& circle, shape::rectangle& rect)
{
    float dist_x = abs(circle.getXposition() - (rect.getXposition() + rect.getWidth() /2));
    float dist_y = abs(circle.getYposition() - (rect.getYposition() + rect.getHeight() /2));

    if (dist_x > (rect.getWidth()/2 + circle.getRadius())) { return false; }
    if (dist_y > (rect.getHeight()/2 + circle.getRadius())) { return false; }

    if (dist_x <= (rect.getWidth()/2)) { return true; } 
    if (dist_y <= (rect.getHeight()/2)) { return true; }

   // float cornerDis = pow((dist_x - rect.getWidth()/2),2) +
     //                    pow((dist_y - rect.getHeight()/2),2);
    float cornerDis = pow((dist_x),2) +
                         pow((dist_y),2);

    return (cornerDis <= (circle.getRadius()^2));
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
    sf::RectangleShape frame(sf::Vector2f(GAME_BOUND, SCREEN_HEIGHT)); 
    frame.setFillColor(sf::Color::Transparent);
    frame.setOutlineColor(sf::Color::White);
    frame.setOutlineThickness(2);
    std::vector<shape::ball> balls;
    setBalls(balls);
    std::vector<shape::ball> lives;
    setLiveBalls(lives);
    std::vector<shape::rectangle> rectangles;
    setRectangles(rectangles);
    std::vector<shape::paddle> paddle;
    setPaddle(paddle);

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
       
        for(auto& e: balls)
        {
            checkFall(e, SCREEN_WIDTH, SCREEN_HEIGHT, lives);
            changeDirection(e, GAME_BOUND, SCREEN_HEIGHT, balls);
            CheckCollision(e, balls);
            e.drawBall(window);
        }

        for(auto& e: balls)
        { 
             for(auto& k: rectangles)
            {   
                if ( intersects(e ,k))
                {
                    if(k.getCollision() > 0)
                    {
                        e.changeXdirection(-1);
                        e.changeYdirection();
                        k.setCollision();
                    }
                    else
                    {
                        k.setColor();
                    }
                    
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
                    if(e.getXposition() < k.getXposition() + k.getWidth() /2)
                    {
                        e.setXdirection(-1);
                    }
                    else
                    {
                        e.setXdirection(1);
                    }
                }
            }
        }

        window.display();

        usleep(3000);
    }

    return 0;
}