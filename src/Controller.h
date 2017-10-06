#pragma once

#include "Model/Object.h"


/**
   @brief Control the game

   States :
       - Active : Controlling a character
       - Passive : Moving along the time line

   Speed of time : 0.0 to 1.0

 */
class Controller{
    Object* _controlled = nullptr;
    bool _activeMode;
    float _simSpeed;
public:
    /**
       @brief Store game events and actions.
    */
    struct Event{
        enum Type{PAUSE,SIMSPEED,ZOOM,MAPMOVE,SHOOT};
        Type type;
        double param;
        double param2;
        friend std::ostream& operator<<(std::ostream& out, Event& event);
    };
    void handleEvent(Event& event); ///< handle an Event
    void step(); ///< move to next frame.
    void selectObject(Object* obj){
        _controlled = obj;
    }
};

extern Controller controller;
