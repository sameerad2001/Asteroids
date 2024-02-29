#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Asteroid.h"
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
    // Game objects
    Player* player;
    Asteroid* asteroid;
    LevelUI* levelUI;

    // Bullet pool
    std::vector<Bullet*> bulletPool;
    const int BULLET_POOL_SIZE = 30;
    const float FIRE_RATE = 5.0f; // bullets per second
    float timeSinceLastBullet = 0;

    // Engine and window
    Engine* engine;
    sf::RenderWindow* window;

    // Game state
    bool isGameOver = false;
    int score = 0;
    int lives = 3;
};