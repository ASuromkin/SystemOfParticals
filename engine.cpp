#include "engine.hpp"
#include "missile.hpp"

Engine::Engine() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = ANTI_ALIASING_LEVEL;
    window = new sf::RenderWindow;
    window->create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Window",sf::Style::Default,settings);
    window->setPosition(sf::Vector2i(2900,180));
    window->setFramerateLimit(120);
    podium.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT / 4));
    podium.setPosition(0, WINDOW_HEIGHT / 4 * 3);
    podium.setFillColor(sf::Color::Green);

    canon.setSize(sf::Vector2f(20, 40));
    canon.setPosition(WINDOW_WIDTH/2 - 10, WINDOW_HEIGHT / 4 * 3 - 40);
    canon.setFillColor(sf::Color::Red);
}

void Engine::Run() {
    while (window->isOpen())
    {

        for(auto& drawobj : drawObjects)
        {
            drawobj->UpdatePosition();
        }

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) { window->close(); }
        }

        window->clear();
        if (drawObjects.empty())
            new Missile(this, 30, sf::seconds(20));

        for(auto& drawobj : drawObjects)
        {
            drawobj->Draw();
        }
        window->draw(podium);
        window->draw(canon);
        window->display();
    }
}

void Engine::AddDrawable(MissileBase *object)
{
    drawObjects.emplace_back(std::move(object));
}

sf::Vector2f Engine::GetCanonPosition() const {
    return canon.getPosition();
}

sf::Vector2f Engine::GetCanonSize() const {
    return canon.getSize();
}

sf::RenderWindow *Engine::GetWindow() const {
    return window;
}
