#ifndef SYSTEMOFPARTICALS_MISSILE_H
#define SYSTEMOFPARTICALS_MISSILE_H

#include "missileBase.hpp"

class Missile : public MissileBase{
public:
    Missile(Engine* engine, uint speed, sf::Time lifeExpectancy);
    void UpdatePosition() override;
    void Draw() override;
    void Explotion();
private:
    sf::CircleShape missile;
    sf::Time lifeExpectancy;
    uint speed;
};


#endif //SYSTEMOFPARTICALS_MISSILE_H
