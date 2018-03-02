#include <SFML/Window.hpp>
#include <iostream>
#include "Model/Model.h"
#include "Controller.h"
#include "Event/EventManager.h"
#include "Render/Renderer.h"
#include "Model/Object.h"
#include "Game.h"

using namespace std;

int main() {
    lg::init();

    Game::start();
    while(true){
        sf::Event event;
        while(Game::win.pollEvent(event)) Game::handleEvent(event);
        Game::update();
    }
}
