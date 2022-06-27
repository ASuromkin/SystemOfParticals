#ifndef SYSTEMOFPARTICALS_MISSILE_H
#define SYSTEMOFPARTICALS_MISSILE_H

#include "missileBase.hpp"
#include <memory>

const float MISSILE_RADIUS = 10.f;

class Missile : public MissileBase{
public:
    Missile(std::shared_ptr<Engine> engine, float speed, sf::Time lifeExpectancy, float angle);
    void Update() override;
    void Draw() override;

    virtual void Explosion();

protected:
    std::shared_ptr<Engine> engine;
    sf::CircleShape missile;
    sf::Time lifeExpectancy;
    sf::Clock clock;
    float speed;
    float angle;
};


#endif //SYSTEMOFPARTICALS_MISSILE_H
