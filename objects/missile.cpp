#include "../includes/missile.hpp"
#include "../includes/partical.hpp"
#include "../includes/smallMissile.hpp"

Missile::Missile(std::shared_ptr<Engine> en, float speed, sf::Time lifeExpectancy, float angle)
:   engine(std::move(en)), speed(speed), lifeExpectancy(lifeExpectancy), angle(angle)
{
    missile.setRadius(MISSILE_RADIUS);
    auto canonPos = engine->GetCanonPosition();
    auto Posx = canonPos.x;
    auto Posy = canonPos.y - MISSILE_RADIUS * 2;
    sf::Vector2f pos = sf::Vector2f(Posx,Posy);
    missile.setPosition(pos);
    missile.setFillColor(sf::Color::Cyan);
}

void Missile::Update(){
    float time = clock.getElapsedTime().asSeconds();
    if(time > lifeExpectancy.asSeconds())
        Explosion();

    auto currentPos = missile.getPosition();

    // Расчет позиции обьекта с учетом гравитации
    auto PosX = currentPos.x + speed * time* cos(angle);
    auto PosY = currentPos.y + speed * time * sin(angle) + G * time * time / 2;

    missile.setPosition(PosX, PosY);

    // Удалить обьект если вышел за границы экрана
    if( missile.getPosition().x > WINDOW_WIDTH || missile.getPosition().x < - missile.getRadius()*2 ||
    missile.getPosition().y < - missile.getRadius()*2 || missile.getPosition().y > WINDOW_HEIGHT / 4 * 3){
        engine->DeleteObject(shared_this<Missile>());
    }
}

void Missile::Draw()
{
    engine->GetWindow()->draw(missile);
}

void Missile::Explosion() {

    srand(time(nullptr));
    auto NumOfSmallMissiles = rand()%3;
    auto missileSpeed = speed  * sin(angle) + G * clock.getElapsedTime().asSeconds();

    for (int i = 0; i < NumOfSmallMissiles; ++i){
        double ang = (rand()%20-10)  * PI / 180;

        auto smallMissile = std::make_shared<SmallMissile>(
                engine,
                missileSpeed * 2,
                sf::seconds(lifeExpectancy.asSeconds() / 2),
                missile.getPosition(),
                angle + ang);

        engine->AddDrawable(smallMissile);
    }


    auto NumOfPartacals = rand()%20 + 10;
    float particalSpeed = speed * float(lifeExpectancy.asSeconds());

    for (int i = 0; i < NumOfPartacals; ++i) {
        double ang = (rand()%360-180)  * PI / 180;

        auto partical = std::make_shared<Partical>(engine,
                     particalSpeed,
                     sf::seconds(lifeExpectancy.asSeconds() / 2 - 0.2),
                     missile.getPosition(),
                     ang);

        engine->AddDrawable(partical);
    }
    engine->DeleteObject(shared_this<Missile>());
}
