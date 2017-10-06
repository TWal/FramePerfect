#pragma once

#include <SFML/Window.hpp>

class Action;


class Phy{
public:
    void action(Action& action);
    void setCharDir(sf::Vector2f dir);
    void step(float speed);
};

extern Phy phy;
