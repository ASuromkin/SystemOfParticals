#ifndef SYSTEMOFPARTICALS_MISSILEBASE_H
#define SYSTEMOFPARTICALS_MISSILEBASE_H

#include "engine.hpp"

class MissileBase{
public:
    MissileBase() = default;
    virtual void UpdatePosition() = 0;
    virtual void Draw() = 0;
protected:
    Engine* engine;
};

#endif //SYSTEMOFPARTICALS_MISSILEBASE_H
