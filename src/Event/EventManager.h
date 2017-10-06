#pragma once

#include <SFML/Window.hpp>

class EventManager {
    bool handleEvent(sf::Event& event);
    enum Checked{UP,DOWN,LEFT,RIGHT};
    bool active(Checked c);
};
