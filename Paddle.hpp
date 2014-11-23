#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle
{
public:
    Paddle(const sf::Vector2f& center, const sf::Vector2f & position, const sf::Vector2f & size, float distance, float angularVel);

    void onUpdate();
    void onDraw(sf::RenderTarget & rt);

    void onMove(float direction);

    const sf::Vector2f & getPosition() { return position; }

private:
    sf::Vector2f arenaCenter;

    sf::RectangleShape rectangle;
    sf::Vector2f position;

    float angularVel;

    float angle;
    float distance;
};

#endif
