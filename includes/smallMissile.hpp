#ifndef SYSTEMOFPARTICALS_SMALLMISSILE_HPP
#define SYSTEMOFPARTICALS_SMALLMISSILE_HPP
#include "missile.hpp"

class SmallMissile : public Missile{
public:
    SmallMissile(std::shared_ptr<Engine> engine, float speed, sf::Time lifeExpectancy, sf::Vector2f position, float angle);
    void Explosion() override;
};


#endif //SYSTEMOFPARTICALS_SMALLMISSILE_HPP
