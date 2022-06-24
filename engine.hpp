#ifndef SYSTEMOFPARTICALS_ENGINE_H
#define SYSTEMOFPARTICALS_ENGINE_H

#include <SFML/Graphics.hpp>

class MissileBase;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int ANTI_ALIASING_LEVEL = 8;

class Engine{
public:
    Engine();
    void Run();
    void AddDrawable(MissileBase* object);
    sf::Vector2f GetCanonPosition() const;
    sf::Vector2f GetCanonSize() const;
    sf::RenderWindow* GetWindow() const;
private:
    sf::RenderWindow* window;
    sf::RectangleShape podium;
    sf::RectangleShape canon;
    std::vector<MissileBase*> drawObjects;
};

#endif //SYSTEMOFPARTICALS_ENGINE_H
