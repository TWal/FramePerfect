#pragma once

#include <SFML/Window.hpp>

class EventManager {
public:
    bool handleEvent(sf::Event& event);
    enum Checked{UP,DOWN,LEFT,RIGHT};
    bool active(Checked c);
};

extern EventManager eventManager;
