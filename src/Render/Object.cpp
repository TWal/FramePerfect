#include "Object.h"
#include "Renderer.h"
#include <iostream>

using namespace std;

void Object::draw(){
    sf::RectangleShape rectangle(sf::Vector2f(50, 50));
    rectangle.setFillColor(sf::Color(255,0,0));
    rectangle.setPosition(pos);
    win.draw(rectangle);
}
