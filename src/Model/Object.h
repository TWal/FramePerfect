#pragma once

#include "../utility.h"

class Object{
public:
    const u64 id;
    const bool shortLived;
    explicit Object(u64 id, bool shortLived = false)
        : id(id), shortLived(shortLived){}
    Object(Object&) = delete;
    Object(Object&&) = delete;

    /// creates a fresh copy allocated on heap
    ///
    /// TODO : think about unique_ptr here.
    virtual Object* copy() const = 0;


    /// one must be a modified copy of the other
    virtual std::vector<u64> operator-(const Object& base) const = 0;
    virtual Object& operator +=(const std::vector<u64>& patch) = 0;
    Object* operator +(const std::vector<u64>& patch) const{
        return &(*(this->copy()) += patch);
    }


    /// All the features an object can provide (only known at runtime)
    /// An object can have other parameter that do not interact directly with the
    /// game but only with its internal mechanics
    enum class Features {
        POS = 1, /// Position (x, y ,theta)
        SPD = 2, /// Speed (dx, dy, dtheta)
        GRAPHICAL = 4, /// has a representation
        PHYSICAL = 8, /// object has physical existence
        BB = 16, /// Bounding box (physical => bounding box)
        /// Controlled : can be controlled by the player (WASD for example)
        /// This attribute implies the field TSPD(Target Speed)
        /// and the abilities to do actions like SHOOT
        CTRL = 32,
        LIFE = 64, /// destructible object (if not enable, is not destructible)
    };
    virtual void move(Vector2r){};
    virtual Vector2r pos() const {return {};}

    virtual void chgSpd(Vector2r){}
    virtual Vector2r spd() const {return {};}

    /// Available if GRAPHICAL, draws the object on screen
    /// 
    /// (Do not takes care of bounding boxes or occlusion, The renderer takes care of that)
    /// If object is not graphical, must do nothing.
    virtual void draw(){}

    /// check collisons, ... and other physical stuff TODO

    virtual RealRect getBB() const {return {};}

    enum class CtrlAction {
        SHOOT, // ...
    };
    virtual void setTargetSpd(Vector2r){}
    virtual Vector2r getTargetSpd() const {return {};}
};
