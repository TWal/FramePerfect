#include "Game.h"
#include "GUI/GUI.h"
#include "Event/EventManager.h"

class Level{};

Game::Mode Game::mode = Game::Mode::Prestart;

Level Game::lvl;

sf::RenderWindow Game::win;


void Game::start(){
    win.create(sf::VideoMode(800, 600), "FramePerfect");
}

void Game::update(){
    Game::render();
}

void Game::render() {
    win.clear(sf::Color::Black);
    //rendering
    win.display();
}

bool Game::handleinternalEvent(const sf::Event& event) {
    if(event.type == sf::Event::Closed) quit();
    return false;
}

void Game::handleEvent(const sf::Event& event) {
    if(handleinternalEvent(event)) return;
    if(GUI::handleEvent(event)) return;
    if(mode == Mode::Game) EventManager::handleEvent(event);
}

void Game::returnToMenu() {
}

void Game::quit() {
    win.close();
    // other deinitializing
    exit(0);
}

