#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Asteroids.h"
#include "Bullet.h"
#include "Engine.h"
#include "EventSystem.h"
#include "Player.h"
#include "UISystem.h"

class LevelUI;
class Game : public EventListener
{
public :
    Game(sf::RenderWindow* window);
    ~Game();

    void Update(float dt);

    int GetScore() const { return score; };
    int GetLives() const { return lives; };
    void ReceiveEvent(const EventType eventType);

protected :
    Player* player;
    Asteroids* asteroids;
    LevelUI* levelUI;
    std::vector<Bullet*> bulletPool;
    const int BULLET_POOL_SIZE = 10;

    Engine* engine;

    sf::RenderWindow* window;

    bool isGameOver = false;
    int score = 0;
    int lives = 3;
};