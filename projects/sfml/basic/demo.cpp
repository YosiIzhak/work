#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

unsigned int SCREEN_WIDTH = 500;
unsigned int SCREEN_HEIGHT = 500;

void collision(sf::CircleShape& ball, sf::RectangleShape& frame, sf::Vector2f& direction);

int main()
{
        sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "my circle", sf::Style::Close);
        window.setFramerateLimit(60);

        sf::Clock clock;
        sf::Event windowEvent;
        float elapsedTime = 0.0f;

        sf::RectangleShape frame(sf::Vector2f(500, 500));
        frame.setOutlineThickness(2.0f);
        frame.setOutlineColor(sf::Color::White);
        frame.setFillColor(sf::Color::Transparent);
        frame.setPosition(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f);
        frame.setOrigin(frame.getGlobalBounds().width/2, frame.getGlobalBounds().height/2);

        sf::CircleShape ball;
        ball.setRadius(20.0f);
        ball.setPosition(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f + 120.0f);
        ball.setOrigin(ball.getGlobalBounds().width/2, ball.getGlobalBounds().height/2);
        ball.setFillColor(sf::Color::Red);
        sf::Vector2f direction(1.0f, 0.0f);
        float ballSpeed = 200.0f;

        sf::CircleShape ball2;
        ball2.setRadius(20.0f);
        ball2.setPosition(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f - 120.0f);
        ball2.setOrigin(ball2.getGlobalBounds().width/2, ball2.getGlobalBounds().height/2);
        ball2.setFillColor(sf::Color::Green);
        sf::Vector2f direction2(1.0f, 0.0f);
        float ball2Speed = 100.0f;

        while(window.isOpen())
        {
                while(window.pollEvent(windowEvent))
                {
                        if(windowEvent.type == sf::Event::Closed)
                                window.close();
                }

                window.clear(sf::Color());

                ball.move(direction * ballSpeed * elapsedTime);

                if((ball.getRadius() + sqrt(pow(frame.getPosition().x - ball.getPosition().x, 2.0f) + pow(frame.getPosition().y - ball.getPosition().y, 2.0f)) > 250))
                {
                        ball.move(-direction * ballSpeed * elapsedTime);
                        collision(ball, frame, direction);
                }

                ball2.move(direction2 * ball2Speed * elapsedTime);

                if((ball2.getRadius() + sqrt(pow(frame.getPosition().x - ball2.getPosition().x, 2.0f) + pow(frame.getPosition().y - ball2.getPosition().y, 2.0f)) > 250))
                {
                        ball2.move(-direction2 * ball2Speed * elapsedTime);
                        collision(ball2, frame, direction2);
                }

                float dx = (ball.getPosition().x - ball2.getPosition().x); 
		        float dy = (ball.getPosition().y - ball2.getPosition().y);
                float distance = std::sqrt((dx * dx) + (dy * dy));
                if (distance < ball.getRadius() + ball2.getRadius())
                {
                    direction.x *= -1.0f;
                    direction.y *= -1.0f;
                    direction2.x *= -1.0f;
                    direction2.y *= -1.0f;

                }
                window.draw(frame);
                window.draw(ball);
                window.draw(ball2);

                elapsedTime = clock.restart().asSeconds();
                window.display();
        }

        return EXIT_SUCCESS;
}

void collision(sf::CircleShape& ball, sf::RectangleShape& frame, sf::Vector2f& direction)
{
        float sz, st, sv1, xt1, yt1, xz1, yz1;
        sz = st = sv1 = xt1  = yt1 = xz1 = yz1 = 0.0f;

        sv1 = direction.y / direction.x;
        sz = ((frame.getPosition().y - ball.getPosition().y) / (frame.getPosition().x - ball.getPosition().x));

        if(sz != 0)
        {
                st = -1.0f / sz;

                xt1 = direction.x * (sz - sv1) / (sz - st);
                xz1 = direction.x * (st - sv1) / (st - sz);
                yt1 = xt1 * st;
                yz1 = xz1 * sz;

                sf::Vector2f t1(xt1, yt1);
                sf::Vector2f z1(xz1, yz1);

                direction = (t1 - z1);
        }
        else
        {
                direction.x *= -1.0f;
                direction.y *= -1.0f;
        }
}