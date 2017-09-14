#pragma once

#include <SFML/Graphics.hpp>

class Object{
    sf::Vector2f _pos;
public:
    virtual void draw();
    void move(sf::Vector2f pos);
    sf::Vector2f pos(){return _pos;}
};
