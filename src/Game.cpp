#include "Game.h"
#include "GUI/GUI.h"
#include "Event/EventManager.h"

using namespace std;
using namespace lg;

class Level{};

Game::Mode Game::mode = Game::Mode::Prestart;

Level Game::lvl;

sf::RenderWindow Game::win;


void Game::start(){
    base->info("Starting the game");

    SPDLOG_TRACE(base,"Creating window");
    win.create(sf::VideoMode(800, 600), "FramePerfect");
}

void Game::update(){
    SPDLOG_TRACE(base,"Updating");
    Game::render();
}

void Game::render() {
    SPDLOG_TRACE(lg::render,"Global Rendering");
    win.clear(sf::Color::Black);
    //rendering

    SPDLOG_TRACE(lg::render,"End of drawing : display !");
    win.display();
}

bool Game::handleinternalEvent(const sf::Event& event) {
    if(event.type == sf::Event::Closed) quit();
    return false;
}

void Game::handleEvent(const sf::Event& event) {
    SPDLOG_TRACE(lg::event,"Game received event {}", event);
    if(handleinternalEvent(event)) return;
    if(GUI::handleEvent(event)) return;
    if(mode == Mode::Game) EventManager::handleEvent(event);
}

void Game::returnToMenu() {
}

void Game::quit() {
    base->info("Quitting the game");

    win.close();
    // other deinitializing

    base->info("Deinitializing ok, calling exit");
    exit(0);
}

