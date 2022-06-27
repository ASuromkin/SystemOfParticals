#ifndef SYSTEMOFPARTICALS_PARTICAL_HPP
#define SYSTEMOFPARTICALS_PARTICAL_HPP

#include "missileBase.hpp"

class Partical : public MissileBase {
public:
    Partical(std::shared_ptr<Engine>  engine, float speed, sf::Time lifeExpectancy, sf::Vector2f position, float angle);

    void Update() override;
    void Draw() override;
private:
    std::shared_ptr<Engine> engine;
    sf::CircleShape partical;
    sf::Time lifeExpectancy;
    sf::Clock clock;
    float speed;
    float angle;
};


#endif //SYSTEMOFPARTICALS_PARTICAL_HPP
