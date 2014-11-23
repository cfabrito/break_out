#include "Paddle.hpp"

#include "MathUtil.hpp"

#include <iostream>

using namespace std;


Paddle::Paddle(const sf::Vector2f& center, const sf::Vector2f & position, const sf::Vector2f & size, float distance, float angularVel)
:
arenaCenter(center),
position(position),
angularVel(angularVel),
angle(0.0f),
distance(distance)
{
    rectangle.setSize(size);
    rectangle.setOrigin(size / 2.f);

    rectangle.setPosition(position);

    rectangle.setFillColor(sf::Color::Red);
}

void Paddle::onUpdate()
{

}

void Paddle::onDraw(sf::RenderTarget & rt)
{
    rt.draw(rectangle);
}

void Paddle::onMove(float direction)
{
    angle += direction * angularVel;

    position.x = arenaCenter.x + distance * sin(angle);
    position.y = arenaCenter.y + distance * cos(angle);

    rectangle.setPosition(position);
    rectangle.setRotation(-radToDeg(angle));
}
