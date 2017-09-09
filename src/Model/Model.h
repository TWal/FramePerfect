#pragma once

#include <vector>

class Object;
class Map;

struct Model{
    std::vector<Object*> objects; // owner
    Map* map; //owner
};

extern Model model;
