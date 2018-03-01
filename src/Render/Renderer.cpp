#include "Renderer.h"
#include "../Model/Model.h"
#include "../Model/Object.h"
#include "../Model/Level.h"
#include "../Game.h"

void Renderer::render(){
    for(auto [id,obj] : Game::lvl.current()){
        obj->draw();
    }
}
