#include "missile.hpp"

Missile::Missile(Engine *en, uint speed, sf::Time lifeExpectancy)
:   speed(speed), lifeExpectancy(lifeExpectancy)
{
    engine = en;
    missile.setRadius(10.0f);
    auto canonPos = engine->GetCanonPosition();
    auto canonSize = engine->GetCanonSize();
    auto Posx = canonPos.x;
    auto Posy = canonPos.y - 20.f;
    sf::Vector2f pos = sf::Vector2f(Posx,Posy);
    missile.setPosition(pos);
    missile.setFillColor(sf::Color::Cyan);
    engine->AddDrawable(this);
}

void Missile::UpdatePosition(){
    auto currentPos = missile.getPosition();
    auto direction = sf::Vector2f(2,10);
    missile.setPosition(currentPos.x - direction.x/10, currentPos.y - direction.y / 10);
}

void Missile::Draw()
{
    engine->GetWindow()->draw(missile);
}