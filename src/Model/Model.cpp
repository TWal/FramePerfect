#include "Model.h"
#include "Object.h"

using namespace std;


void Model::add(u64 id, copy_ptr<Object> obj){
    insert(id, move(obj));
}

Object& Model::operator[](u64 id){
    return *at(id);
}
const Object& Model::operator[](u64 id) const {
    return *at(id);
}

void Model::remove(u64 id){
    erase(id);
}

copy_ptr<Object> Model::moveOut(u64 id){
    assert(count(id));
    return move(at(id));
}

Patch Model::operator-(const Model& m){
    Patch res;
    for(auto [id,curobj] : *this){
        res.insert(id,*curobj - *m.at(id));
    }
    return res;
}
Model& Model::operator+=(const Patch& p){
    for(auto [id,curobj] : *this){
        *curobj += p.at(id);
    }
    return *this;
}
