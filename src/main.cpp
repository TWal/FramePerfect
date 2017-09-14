#include <SFML/Window.hpp>
#include <iostream>
#include "Model/Model.h"
#include "Controller.h"
#include "Render/Renderer.h"
#include "Model/Object.h"


using namespace std;

int main() {
    win.create(sf::VideoMode(800, 600), "My window");

    Object obj;
    model.objects.push_back(&obj);
    controller.selectObject(&obj);
    while(win.isOpen()) {
        sf::Event event;
        while(win.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                win.close();
            }
            //else if(!gui.handleEvent(event));
            else controller.handleEvent(event);
        }
        win.clear(sf::Color::Black);
        controller.run();
        renderer.render();
        // gui.draw();
        win.display();
    }



    return 0;
}
