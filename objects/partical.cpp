#include "../includes/partical.hpp"

Partical::Partical(std::shared_ptr<Engine>  engine, float speed, sf::Time lifeExpectancy, sf::Vector2f position, float angle)
        :   engine(std::move(engine)), speed(speed), lifeExpectancy(lifeExpectancy), angle(angle)
{
    partical.setRadius(PARTICAL_RADIUS);
    partical.setPosition(position);
    partical.setFillColor(sf::Color::White);
}

void Partical::Update() {
    float time = clock.getElapsedTime().asSeconds();
    if(time > lifeExpectancy.asSeconds()) {
        engine->DeleteObject(shared_this<Partical>());
        return;
    }
    auto currentPos = partical.getPosition();

    auto PosX = currentPos.x + speed * time * cos(angle);
    auto PosY = currentPos.y + speed * time * sin(angle) + G * time * time / 2;



    partical.setPosition(PosX,PosY);


    // Удалить обьект если вышел за границы экрана
    if(partical.getPosition().x > WINDOW_WIDTH || partical.getPosition().x < - partical.getRadius() * 2 ||
       partical.getPosition().y < - partical.getRadius() * 2 || partical.getPosition().y > (WINDOW_HEIGHT / 4 * 3)){
        engine->DeleteObject(shared_this<Partical>());
    }
}

void Partical::Draw() {
    engine->GetWindow()->draw(partical);
}
