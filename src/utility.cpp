#include "utility.h"

std::ostream& operator<<(std::ostream& out, const sf::Event& event){
    switch(event.type){
        case sf::Event::Closed:
            return out << "Win Closed";
        case sf::Event::Resized:
            return out << "Win resized to (" << event.size.height << ", "
                       << event.size.width << ")" ;
        case sf::Event::LostFocus: return out<<"Win LostFocus";
        case sf::Event::GainedFocus: return out<<"Win GainedFocus";
        case sf::Event::TextEntered:
            return out << "TextEntered : " << (char)event.text.unicode;
        case sf::Event::KeyPressed:
            return out << "KeyPressed : " << event.key.code;
        case sf::Event::KeyReleased:
            return out << "KeyReleased : " << event.key.code;
        case sf::Event::MouseMoved:
            return out << "MouseMoved to (" << event.mouseMove.x
                       << ", " << event.mouseMove.y << ")";
        case sf::Event::MouseEntered:
            return out << "MouseEntered";
        case sf::Event::MouseLeft:
            return out << "MouseLeft";
        case sf::Event::MouseButtonPressed:
            return out << "MouseButtonPressed " << event.mouseButton.button
                       << " at ("  << event.mouseButton.x << ", "
                       << event.mouseButton.y << ")";
        case sf::Event::MouseButtonReleased:
            return out << "MouseButtonReleased " << event.mouseButton.button
                       << " at ("  << event.mouseButton.x << ", "
                       << event.mouseButton.y << ")";
        default:
            return out << "Other event";
            break;
    }
    out << event;
}

bool jsonToVector2u(const json& j, sf::Vector2u& out) {
    if(!j.is_array()) return false;
    if(j.size() != 2) return false;
    for(size_t i = 0; i < 2; ++i) {
        if(!j[i].is_number_unsigned()) return false;
    }

    out.x = j[0];
    out.y = j[1];

    return true;
}
