#include "Bullet.h"

Bullet::Bullet(sf::RenderWindow* window, const sf::Vector2f& initialPosition, const sf::Vector2f& initialDirection) {
    bulletTexture.loadFromFile("Assets/Asteroid.png");
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setScale(0.5f, 0.5f);
    bulletPosition = initialPosition;
    bulletVelocity = initialDirection;

    this->window = window;
}

void Bullet::Update(float dt) {
    bulletPosition += bulletVelocity * dt;

    sf::Vector2u windowSize = window->getSize();
    if (bulletPosition.x < 0 || 
        bulletPosition.x > windowSize.x || 
        bulletPosition.y < 0 || 
        bulletPosition.y > windowSize.y) {
        isOutOfBounds = true;
    }
}

void Bullet::Draw() {
    bulletSprite.setPosition(bulletPosition);
    window->draw(bulletSprite);
}

void Bullet::SetPositionAndDirection(const sf::Vector2f& newPosition, const sf::Vector2f& newDirection)
{
    bulletPosition = newPosition;
    bulletVelocity = newDirection;
    isOutOfBounds = false;
}
