#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

class Game
{
public:
    Game();

    int execute();

private:
    bool onInit();
    void onUpdate();
    void onDraw();
    void onExit();

private:
    bool running;

    sf::ContextSettings settings;
    sf::RenderWindow window;
    sf::View view;

    Paddle *paddle;

    /* Stuff that will go */
    sf::CircleShape arena;
};

#endif
