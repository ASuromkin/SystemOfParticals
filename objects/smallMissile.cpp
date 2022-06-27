#include "../includes/smallMissile.hpp"
#include "../includes/partical.hpp"

SmallMissile::SmallMissile(std::shared_ptr<Engine> engine, float speed, sf::Time lifeExpectancy, sf::Vector2f position, float angle)
    : Missile(std::move(engine), speed, lifeExpectancy, angle)
{
    missile.setRadius(SMALL_MISSILE_RADIUS);
    missile.setPosition(position);
    missile.setFillColor(sf::Color::Magenta);
}

void SmallMissile::Explosion() {
    srand(time(nullptr));
    auto NumOfPartacals = rand()%20 + 10;
    float particalSpeed = speed * float(lifeExpectancy.asSeconds()/2);
    for (int i = 0; i < NumOfPartacals; ++i) {
        float ang = (rand()%360-180)  * PI / 180;

        auto partical = std::make_shared<Partical>(engine,
                     particalSpeed,
                     sf::seconds(lifeExpectancy.asSeconds() / 2),
                     missile.getPosition(),
                     ang);

        engine->AddDrawable(partical);
    }
    engine->DeleteObject(shared_this<SmallMissile>());
}
