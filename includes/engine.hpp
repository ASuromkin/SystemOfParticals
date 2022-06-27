#ifndef SYSTEMOFPARTICALS_ENGINE_H
#define SYSTEMOFPARTICALS_ENGINE_H

#include <SFML/Graphics.hpp>
#include <cmath>

#include "sharedFromThisHelper.hpp"

class MissileBase;

const int WINDOW_WIDTH = 2000;
const int WINDOW_HEIGHT = 1500;
const int G = 7;
const int ANTI_ALIASING_LEVEL = 8;

const double PI = std::acos(-1);

class Engine : public InheritableEnableSharedFromThis<Engine> {
public:
    Engine();
    void Run();
    void AddDrawable(const std::shared_ptr<MissileBase>& object);
    sf::Vector2f GetCanonPosition() const;
    std::shared_ptr<sf::RenderWindow> GetWindow() const;
    static float GetRandomAngle(int range, int offset);
    static float GetRandomSpeed();
    static float GetRandomTime();
    void DeleteObject(const std::shared_ptr<MissileBase>& obj);
private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::RectangleShape podium;
    sf::RectangleShape canon;
    std::vector<std::shared_ptr<MissileBase>> drawObjects;
    std::vector<std::shared_ptr<MissileBase>> eraseList;
};

#endif //SYSTEMOFPARTICALS_ENGINE_H
