#include "Bullet.h"

Bullet::Bullet(sf::RenderWindow* window, const sf::Vector2f& initialPosition, const sf::Vector2f& initialDirection) {
    bulletTexture.loadFromFile("Assets/Asteroid.png");
    bulletSprite = new sf::Sprite();
    bulletSprite->setTexture(bulletTexture);
    bulletSprite->setOrigin(bulletTexture.getSize().x / 2.0f, bulletTexture.getSize().y / 2.0f);\
    bulletSprite->setScale(0.1f, 0.1f);
    bulletPosition = initialPosition;
    bulletDirection = initialDirection;
    bulletVelocity = sf::Vector2f(0, 0);
    bulletSprite->setPosition(window->getView().getCenter());

    PhysicsBody* physicsBody = new PhysicsBody();
    PhysicsVolume* physicVolume = new AABBVolume(bulletSprite);
    physicsBody->SetPhysicsVolume(physicVolume);
    this->SetPhysicsBody(physicsBody);

    timeLeft = LIFE_TIME;
    this->window = window;
}

Bullet::~Bullet(){
    delete bulletSprite;
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

    bulletSprite->setPosition(bulletPosition);
    timeLeft -= dt;
    timeSinceCollision += dt;
}

void Bullet::Draw(sf::RenderWindow* window) {
    window->draw(*bulletSprite);
}

void Bullet::ResetBullet(const sf::Vector2f& newPosition, const sf::Vector2f& newDirection)
{
    bulletPosition = newPosition;
    bulletDirection = newDirection;
    timeLeft = LIFE_TIME;
    SetIsActive(true);
}

void Bullet::OnCollision(GameObject* other) {
    if (other->GetTag() == "Asteroid" && timeSinceCollision > COLLISION_GRACE_PERIOD) {
        EventEmitter::EmitEvent(BULLET_ASTEROID_COLLISION);
        Asteroid* asteroid = dynamic_cast<Asteroid*>(other);
        AsteroidType type = asteroid->GetAsteroidType();
        if (type == SMALL)
        {
            asteroid->SetIsActive(false);
            return;
        }
        asteroid->SetAsteroidType(static_cast<AsteroidType>(type - 1));
        timeSinceCollision = 0;
    }
}