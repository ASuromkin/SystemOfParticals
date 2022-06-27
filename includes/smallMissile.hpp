#ifndef SYSTEMOFPARTICALS_SMALLMISSILE_HPP
#define SYSTEMOFPARTICALS_SMALLMISSILE_HPP
#include "missile.hpp"

const float SMALL_MISSILE_RADIUS = 5.0f;
class SmallMissile : public Missile{
public:
    SmallMissile(std::shared_ptr<Engine> engine, float speed, sf::Time lifeExpectancy, sf::Vector2f position, float angle);
    void Explosion() override;
};


#endif //SYSTEMOFPARTICALS_SMALLMISSILE_HPP
