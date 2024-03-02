#pragma once
#include <SFML/Graphics.hpp>
#include "Asteroid.h"
#include "AsteroidPool.h"
#include "EventSystem.h"
#include "GameObject.h"

class Bullet : public GameObject {
public :
    Bullet(
        sf::RenderWindow* window, 
        const sf::Vector2f& initialPosition, 
        const sf::Vector2f& initialDirection, 
        AsteroidPool* asteroidPool);
    ~Bullet() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow* window) override;
    void OnCollision(GameObject* other) override;
    void ResetBullet(const sf::Vector2f& newPosition, const sf::Vector2f& newDirection);

protected :
    sf::Sprite* bulletSprite;
    sf::Texture bulletTexture;
    sf::Vector2f bulletPosition;
    sf::Vector2f bulletDirection;
    sf::Vector2f bulletVelocity;
    sf::RenderWindow* window;

    float timeLeft;
    const int LIFE_TIME = 10; //seconds
    const int SPEED = 1000;

    int COLLISION_GRACE_PERIOD = 0.1; // Otherwise there will be multiple collisions
    float timeSinceCollision = COLLISION_GRACE_PERIOD + 10;

    AsteroidPool* asteroidPool; // Required because after bullet collision, asteroids must be split
};