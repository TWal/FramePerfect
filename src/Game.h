#pragma once

#include "utility.h"

class Level;
/// Represent the global state of the game, static only class
class Game{
public:
    /// Debugging system
    enum class DbgLvl {
        Normal, ///< Normal game, boot on the menus
        HardCoded ///< Load an harcoded level in by calling hardcodedlvl
    };
    static const DbgLvl dbglvl = DbgLvl::HardCoded;

    enum class Mode {
        Prestart, ///< First millisecond of game, loading non-game systems (like logging system)
        Launch, ///< Launch screen , load sprites, ...
        Menu, ///< In start menu
        Game, ///< In game
        Loading, ///< In loading screen
        Credits, ///< Who look at that anyway
        // Others to be added
    };
private:
    /// Current game mode
    static Mode mode;

    /// Loads the hardcoded level.
    static void loadHardCoded();

    /// Handle a program wide event, like quitting, focus lost, etc.
    static bool handleinternalEvent(const sf::Event&);

public:
    static Mode getMode(){return mode;}

    static sf::RenderWindow win;

    /// Starts the game, load screen an go to Menu (or directly to lvl if in HardCoded mode)
    static void start();

    /// Update the game, must be called often
    ///
    /// This function can be called with no predefined frequency. It will handle
    /// any specific frequencies need by subsystems
    static void update();

    static void render();

    /// Handle a new event
    static void handleEvent(const sf::Event&);

    static Level lvl;

    /// Load the save and go to Mode::Game (passing by Game::Loading)
    static void loadSave(int/*to be replaced type*/ save);

    /// Close current game and return to Menu
    static void returnToMenu();

    /// Quit the game and the program
    [[noreturn]] static void quit();
};
