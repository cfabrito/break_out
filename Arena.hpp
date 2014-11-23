#ifndef ARENA_HPP
#define ARENA_HPP

class Arena
{
public:
    Arena(float x, float y, float radius);

    void onDraw();

private:
    sf::CircleShape circleShape;
}

#endif
