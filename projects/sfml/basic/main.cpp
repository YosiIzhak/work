#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <utility>
#include <unordered_map>
#include <cmath>
#include "ball.hpp"
#include "rectangle.hpp"
#include "paddle.hpp"

int SCREEN_WIDTH = 700;
int SCREEN_HEIGHT = 400;

void isEqual(shape::ball& a_first, shape::ball& a_second);


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
       if (x < SCREEN_WIDTH - a_paddle.getWidth())
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

void changeDirection(shape::ball& a_ball, size_t a_width, size_t a_length, std::vector<shape::ball>& a_balls)
{
    if(a_ball.getXposition() >= (int)(a_width - a_ball.getRadius()*2)
    ||
       a_ball.getXposition() <=  0 )
    {
        a_ball.changeXdirection();
    }

    if(a_ball.getYposition() >= (int)(a_length - a_ball.getRadius()*2)
    ||
        a_ball.getYposition() <=  0)
    {
        a_ball.changeYdirection();
    }
}

void setBalls(std::vector<shape::ball>& a_balls)
{
    a_balls.push_back(shape::ball(15, sf::Color::Blue,100, 0, 2));
    a_balls.push_back(shape::ball(20, sf::Color::Red,0, 50));
    a_balls.push_back(shape::ball(15, sf::Color::Green,200, 0, 3));
    a_balls.push_back(shape::ball(20, sf::Color::Yellow,0, 300));
    a_balls.push_back(shape::ball(20, sf::Color::Cyan,300, 0, 2));
    a_balls.push_back(shape::ball(15, sf::Color::Magenta ,0, 450));
    a_balls.push_back(shape::ball(15, sf::Color::White,400, 0));
}

void setRectangles(std::vector<shape::rectangle>& a_rectangles)
{
    sf::Vector2f size1 = {40, 20}; 
    a_rectangles.push_back(shape::rectangle(size1, sf::Color::Blue,100, 200, 1));
    a_rectangles.push_back(shape::rectangle(size1, sf::Color::Red, 400, 200, 2));

}

void setPaddle(std::vector<shape::paddle>& a_paddle)
{
    sf::Vector2f size1 = {80, 20}; 
    a_paddle.push_back(shape::paddle(size1, sf::Color::Blue,350, 350, 1));
}

void CheckCollision(shape::ball& a_ball, std::vector<shape::ball>& a_balls)
{
    for(auto& e : a_balls)
    {
        if(a_ball == e){}
        else{
            isEqual(a_ball, e);
        }
    }
}

void isEqual(shape::ball& a_first, shape::ball& a_second)
{
    float dx = a_first.getXposition() - a_second.getXposition();
    float dy = a_first.getYposition() - a_second.getYposition();
    float distance = std::sqrt((dx*dx) +(dy*dy));
    if(distance <= a_first.getRadius() + a_second.getRadius())
    {
        a_second.changeXdirection();
        a_second.changeYdirection();
    }
}

bool intersects(shape::ball& circle, shape::rectangle& rect)
{
    float dist_x = abs(circle.getXposition() - rect.getXposition());
    float dist_y = abs(circle.getYposition() - rect.getYposition());

    if (dist_x > (rect.getWidth()/2 + circle.getRadius())) { return false; }
    if (dist_y > (rect.getHeight()/2 + circle.getRadius())) { return false; }

    if (dist_x <= (rect.getWidth()/2)) { return true; } 
    if (dist_y <= (rect.getHeight()/2)) { return true; }

    float cornerDis = pow((dist_x - rect.getWidth()/2),2) +
                         pow((dist_y - rect.getHeight()/2),2);

    return (cornerDis <= (circle.getRadius()^2));
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");

    std::vector<shape::ball> balls;
    setBalls(balls);
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
        for(auto& f: paddle)
        {
            setPaddlePosition(f); 
            f.drawPaddle(window); 
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
            changeDirection(e, 700, 400, balls);
            CheckCollision(e, balls);
            e.drawBall(window);
        }

        for(auto& e: balls)
        { 
             for(auto& k: rectangles)
            {   
                if ( intersects(e ,k))
                {
                    e.changeXdirection();
                    e.changeYdirection();
                }
            }
        }

        window.display();

        usleep(3000);
    }

    return 0;
}