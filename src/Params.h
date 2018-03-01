#pragma once

#include <string>
#include <optional>
#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>
//#include "EventManager.h"
#include "utility.h"

using json = nlohmann::json;

enum Event {
    Meh = 0,
    Moh,
    Count
};

class Params {
    public:
        struct {
            sf::Vector2u windowSize = sf::Vector2u(800, 600);
            bool fullscreen = false;
        } graphics;

        //TODO: default configuration
        std::optional<sf::Keyboard::Key> events[Event::Count];

        Params(const std::string& filename);

    private:
        std::unordered_map<std::string, sf::Keyboard::Key> str2key;
        std::unordered_map<sf::Keyboard::Key, std::string> key2str;
        std::unordered_map<std::string, Event> str2evt;
        std::unordered_map<Event, std::string> evt2str;
        void buildMap();
        void readGraphics(const json& j);
        void readEvents(const json& j);
};

