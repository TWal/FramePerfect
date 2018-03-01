#pragma once

#include <SFML/Window.hpp>

class EventManager {
public:
    static bool handleEvent(const sf::Event& event);
    enum Checked{UP,DOWN,LEFT,RIGHT};
    static bool active(Checked c);
};
