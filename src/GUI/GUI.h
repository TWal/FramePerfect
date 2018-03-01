#pragma once
#include "../utility.h"


/// This static class manages the whole GUI infrastructure
class GUI{
public:
    /// Handles an event from the GUI point of view
    ///
    /// Returns true if the event has been handled by the GUI,
    /// and should not be passed to the game beneath.
    /// Moving mouse event should not pass trough.
    static bool handleEvent(const sf::Event& event){return false;}

    /// Draws the GUI on Game::win
    static void draw(){}

    /// Says if the game should be rendered or if the GUI covers the whole screen
    static bool gameShouldRender(){return true;}

    /// Says if the mouse if over a GUI element or not (if false, it is over a game area)
    static bool hasMouse(){return false;}
};
