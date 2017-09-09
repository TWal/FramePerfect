#pragma once
#include <SFML/Window.hpp>


//∕ Control the game
class Controller{
public:
    bool handleEvent(sf::Event& event); ///< handle an event
    void run(); ///< move to next frame.
};

extern Controller controller;
