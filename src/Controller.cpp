#include <iostream>
#include <SFML/Window.hpp>
#include "Controller.h"
#include "utility.h"

Controller controller;

using namespace std;

bool Controller::handleEvent(sf::Event& event){
    cout << event << endl;
    if(event.type == sf::Event::KeyPressed){
        switch(event.key.code){
            case sf::Keyboard::Z:
                if(controlled){
                    controlled->move(controlled->pos() - sf::Vector2f(0,1));
                }
                break;
            case sf::Keyboard::Q:
                if(controlled){
                    controlled->move(controlled->pos() - sf::Vector2f(1,0));
                }
                break;
            case sf::Keyboard::S:
                if(controlled){
                    controlled->move(controlled->pos() + sf::Vector2f(0,1));
                }
                break;
            case sf::Keyboard::D:
                if(controlled){
                    controlled->move(controlled->pos() + sf::Vector2f(1,0));
                }
                break;
        }
    }
    return true;
}


void Controller::run(){
}
