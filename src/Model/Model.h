#pragma once

#include <vector>
#include <unordered_map>
#include <memory>
#include "../utility.h"
#include "volmap.h"
#include "copy_ptr.h"

class Object;

class Patch : private volmap<std::vector<u64>>{
    Patch(){};
public:
    friend class Model;
};



/// Represent the state of the game level at a given point in time
///
/// Internally a model is a mapping from identifiers to Object
/// A model owns all the objects it is given. For example if you add two objects
/// to one id. The first one will be destroyed.
///
/// The model class makes distinction between volatile object and durable objects
/// The only impact of messing with this difference is performances. The semantic
/// behavior will be same for both of them.
class Model : private volmap<copy_ptr<Object>>{
public:
    using volmap::iterator;
    using volmap::begin;
    using volmap::end;
    /// add an objects to an id. Overwrite if their is already somethins
    void add(u64 id, copy_ptr<Object> obj);
    Object& operator[](u64 i);
    const Object& operator[](u64 id) const;
    void remove(u64 id);
    copy_ptr<Object> moveOut(u64 id);
    Patch operator-(const Model& m);
    Model& operator+=(const Patch& p);
};

inline Model operator+(Model m, const Patch& p){
    return m += p;
}

