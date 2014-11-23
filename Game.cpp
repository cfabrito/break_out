#include "Game.hpp"
#include "MathUtil.hpp"

#include <iostream>

Game::Game()
:
running(true)
{

}

int Game::execute()
{
    if(!onInit())
        return -1;

    while(window.isOpen())
    {
        onUpdate();
        onDraw();
    }

    return 0;
}

bool Game::onInit()
{
/* Load from JSON */

    /* Window definition */

    int width = 800;
    int height = 600;

    settings.antialiasingLevel = 8;

    window.create(sf::VideoMode(width,height), "break_out", sf::Style::Close, settings);

    /* Arena Definition */

    int pointCount = 50;
    float outline = 10;
    float arenaRadius = height/2 - outline;

    sf::Vector2f arenaCenter(width / 2, height / 2);

    arena.setPointCount(pointCount);
    arena.setPosition(arenaCenter - sf::Vector2f(arenaRadius, arenaRadius));
    arena.setRadius(arenaRadius);
    arena.setOutlineThickness(outline);

    arena.setFillColor(sf::Color::Cyan);
    arena.setOutlineColor(sf::Color::Blue);

    /* Paddle */

    float paddleAngle = M_PI / 25;

    sf::Vector2f paddleDimensions;

    paddleDimensions.x = 2 * sin(paddleAngle) * arenaRadius;
    paddleDimensions.y = 15;

    sf::Vector2f paddlePosition;

    paddlePosition.x = arenaCenter.x;
    paddlePosition.y = arenaCenter.y + cos (paddleAngle) * arenaRadius - paddleDimensions.y/2;

    /* View definition */

    view.setSize(400, 300);
    view.setCenter(width/2, height/2 + arenaRadius);

    paddle = new Paddle(arenaCenter, paddlePosition, paddleDimensions, arenaRadius - outline, 0.01f);

    return true;
}

void Game::onUpdate()
{
    sf::Event event;

    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            window.close();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        paddle->onMove(-1);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        paddle->onMove(1);
    }

    view.setCenter(paddle->getPosition());

}

void Game::onDraw()
{
    window.clear(sf::Color::Cyan);

    //window.setView(view);

    window.draw(arena);

    paddle->onDraw(window);

    window.display();
}

void Game::onExit()
{

}
