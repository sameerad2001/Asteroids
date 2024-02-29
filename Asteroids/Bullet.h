#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Bullet : public GameObject {
public :
    Bullet(sf::RenderWindow* window, const sf::Vector2f& initialPosition, const sf::Vector2f& initialDirection);
    ~Bullet() override {};
    void Update(float dt) override;
    void Draw() override;
    void OnCollisionBegin(GameObject* other) override {};
    void ResetBullet(const sf::Vector2f& newPosition, const sf::Vector2f& newDirection);

protected :
    sf::Sprite bulletSprite;
    sf::Texture bulletTexture;
    sf::Vector2f bulletPosition;
    sf::Vector2f bulletDirection;
    sf::Vector2f bulletVelocity;
    sf::RenderWindow* window;

    float timeLeft;
    const int LIFE_TIME = 10; //seconds
    const int SPEED = 1000;
};