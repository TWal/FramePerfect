#pragma once

#include <ostream>
#include <SFML/Window.hpp>

std::ostream& operator<<(std::ostream& out, const sf::Event& event);
