#include <iostream>
#include <SFML/Window.hpp>
#include "Controller.h"
#include "utility.h"
#include "Phy.h"

Controller controller;

using namespace std;


std::ostream& operator<<(std::ostream& out, Controller::Event& event){
    switch(event.type){
        case Controller::Event::PAUSE: return out << "PAUSE";
        default: return out << "Event::TODO";
    }
}

void Controller::handleEvent(Event& event){
    cout << event << endl;
    switch(event.type){
        default: return;
    }
}


void Controller::step(){
    if(_activeMode){
        phy.step(_simSpeed);
    }
    
}
