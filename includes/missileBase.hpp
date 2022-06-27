#ifndef SYSTEMOFPARTICALS_MISSILEBASE_H
#define SYSTEMOFPARTICALS_MISSILEBASE_H

#include "engine.hpp"
#include <utility>

class MissileBase : public InheritableEnableSharedFromThis<MissileBase>{
public:
    MissileBase() = default;
    virtual void Update() = 0;
    virtual void Draw() = 0;
protected:
};

#endif //SYSTEMOFPARTICALS_MISSILEBASE_H
