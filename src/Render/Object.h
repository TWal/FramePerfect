#pragma once

#include <SFML/Graphics.hpp>

class Object{
    sf::Vector2f pos;
public:
    virtual void draw();
};
