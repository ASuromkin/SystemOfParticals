#include "includes/engine.hpp"
#include "includes/missile.hpp"
#include <ctime>

Engine::Engine() {

    //Настройка Окна SFML
    sf::ContextSettings settings;
    settings.antialiasingLevel = ANTI_ALIASING_LEVEL;
    window = std::make_shared<sf::RenderWindow>();
    window->create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Window",sf::Style::Default,settings);
    window->setPosition(sf::Vector2i(500,100));
    window->setFramerateLimit(60);

    // Создание подиума
    podium.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT / 4));
    podium.setPosition(0, WINDOW_HEIGHT / 4 * 3);
    podium.setFillColor(sf::Color::Green);

    // Создание пушки
    canon.setSize(sf::Vector2f(PODIUM_WIDTH, PODIUM_HEIGHT));
    canon.setPosition(WINDOW_WIDTH/2 - PODIUM_WIDTH / 2, WINDOW_HEIGHT / 4 * 3 - PODIUM_HEIGHT);
    canon.setFillColor(sf::Color::Red);
}

void Engine::Run() {
    while (window->isOpen())
    {
        for (const auto& drawObj : drawObjects) {
            drawObj->Update();
        }

        for(const auto& erase : eraseList){
            for (auto itr = drawObjects.begin(); itr < drawObjects.end(); ++itr) {
                if (*itr == erase){
                    itr = drawObjects.erase(itr);
                }
            }
        }
        eraseList.clear();

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window->close(); }
        }
        window->clear();


        if (drawObjects.empty()) {
            float angle = GetRandomAngle(90,-135) * PI/180;
            float speed = GetRandomSpeed();
            float time = GetRandomTime();
            auto missile = std::make_shared<Missile>(shared_this<Engine>(), speed, sf::seconds(time), angle);
            AddDrawable(missile);
        }


        for(auto& drawobj : drawObjects)
        {
            drawobj->Draw();
        }

        window->draw(podium);
        window->draw(canon);
        window->display();
    }
}

void Engine::AddDrawable(const std::shared_ptr<MissileBase>& object)
{
    drawObjects.emplace_back(object);
}

sf::Vector2f Engine::GetCanonPosition() const {
    return canon.getPosition();
}

std::shared_ptr<sf::RenderWindow> Engine::GetWindow() const {
    return window;
}

float Engine::GetRandomAngle(int range, int offset) {
    srand(time(nullptr));
    float angle = rand()%range + offset ;
    return angle;
}
float Engine::GetRandomSpeed() {
    srand(time(nullptr));
    float speed = rand()%3 + 7;
    return speed;
}

void Engine::DeleteObject(const std::shared_ptr<MissileBase>& obj) {
    eraseList.emplace_back(obj);
}

float Engine::GetRandomTime() {
    srand(time(nullptr));
    float time = rand()%2 + 2;
    return time;
}
