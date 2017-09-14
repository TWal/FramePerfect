#pragma once
#include <SFML/Window.hpp>

#include "Model/Object.h"


/**
   @brief Control the game

   States :
       - Active : Controlling a character
       - Passive : Moving along the time line

   Speed of time : 0.0 to 1.0

 */
class Controller{
    Object* controlled = nullptr;
public:
    bool handleEvent(sf::Event& event); ///< handle an event
    void run(); ///< move to next frame.
    void selectObject(Object* obj){
        controlled = obj;
    }
};

extern Controller controller;
