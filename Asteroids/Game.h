#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Asteroid.h"
#include "AsteroidPool.h"
#include "Bullet.h"
#include "Engine.h"
#include "EventSystem.h"
#include "Player.h"
#include "UISystem.h"
#include "Scene.h"
#include "SceneManager.h"

class LevelUI;
class Game : public EventListener, public Scene
{
public :
    Game(sf::RenderWindow* window);
    ~Game() override;

    void Update(float dt) override;
    void TransitionScene() override;

    int GetScore() const { return score; };
    int GetLives() const { return lives; };
    void ReceiveEvent(const EventType eventType);

protected :
    // Game objects
    Player* player;
    LevelUI* levelUI;

    // Bullet pool
    std::vector<Bullet*> bulletPool;
    const int BULLET_POOL_SIZE = 30;
    const float FIRE_RATE = 12.0f; // <rate> bullets per second
    float timeSinceLastBullet = 0;

    // Asteroids
    AsteroidPool* asteroidPool;
    float timeSinceLastAsteroid = 0;
    int ASTEROID_SPAWN_TIME = 5; // asteroid every <time> second(s)
    int AFTER_DEATH_GRACE_PERIOD = 5;
    float timeSinceDeath = 0;

    // Engine and window
    Engine* engine;
    sf::RenderWindow* window;

    // Game state
    int score = 0;
    int lives = 3;
};