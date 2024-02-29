#include "Bullet.h"

Bullet::Bullet(sf::RenderWindow* window, const sf::Vector2f& initialPosition, const sf::Vector2f& initialDirection) {
    bulletTexture.loadFromFile("Assets/Asteroid.png");
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setScale(0.5f, 0.5f);
    bulletPosition = initialPosition;
    bulletDirection = initialDirection;
    bulletVelocity = sf::Vector2f(0, 0);

    timeLeft = LIFE_TIME;
    this->window = window;
}

void Bullet::Update(float dt) {
    bulletVelocity = sf::Vector2f(bulletDirection.x * SPEED, bulletDirection.y * SPEED);
    bulletPosition += bulletVelocity * dt;

    sf::Vector2u windowSize = window->getSize();
    if (timeLeft <= 0 ||
        bulletPosition.x < 0 || 
        bulletPosition.x > windowSize.x || 
        bulletPosition.y < 0 || 
        bulletPosition.y > windowSize.y) {
        SetIsActive(false);
    }

    timeLeft -= dt;
}

void Bullet::Draw() {
    bulletSprite.setPosition(bulletPosition);
    window->draw(bulletSprite);
}

void Bullet::ResetBullet(const sf::Vector2f& newPosition, const sf::Vector2f& newDirection)
{
    bulletPosition = newPosition;
    bulletDirection = newDirection;
    timeLeft = LIFE_TIME;
    SetIsActive(true);
}
