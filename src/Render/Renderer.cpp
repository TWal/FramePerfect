#include "Renderer.h"
#include "../Model/Model.h"
#include "../Model/Object.h"
Renderer renderer;
sf::RenderWindow win;

void Renderer::render(){
    for(Object* obj : model.objects){
        obj->draw();
    }
}
