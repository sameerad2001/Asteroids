#include "Asteroid.h"
#include <cstdlib>
#include <ctime>

std::unordered_map<AsteroidType, float> scaleFactors = {
   {BIG, 1.0f},
   {MEDIUM, 0.5f},
   {SMALL, 0.25f}
};

Asteroid::Asteroid(sf::RenderWindow* window, AsteroidType type) {
    this->window = window;
    this->asteroidType = type;

    asteroidTexture.loadFromFile("Assets/Asteroid.png");
    asteroidSprite = new sf::Sprite();
    asteroidSprite->setTexture(asteroidTexture);
    asteroidSprite->setOrigin(asteroidTexture.getSize().x / 2.0f, asteroidTexture.getSize().y / 2.0f);
    asteroidSprite->setScale(asteroidType * 0.3, asteroidType * 0.3);

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Random seed generation
    sf::Vector2u windowSize = window->getSize();
    float posX = static_cast<float>(std::rand() % windowSize.x);
    float posY = static_cast<float>(std::rand() % windowSize.y);
    asteroidPosition = sf::Vector2f(posX, posY);

    float angle = static_cast<float>(std::rand() % 360);
    float radians = angle * (3.14 / 180.0f);
    static const float SPEED = 100.0f;
    float velX = std::cos(radians) * SPEED;
    float velY = std::sin(radians) * SPEED;
    asteroidVelocity = sf::Vector2f(velX, velY);

    PhysicsBody* physicsBody = new PhysicsBody();
    PhysicsVolume* physicVolume = new AABBVolume(asteroidSprite);
    physicsBody->SetPhysicsVolume(physicVolume);
    this->SetPhysicsBody(physicsBody);

    this->SetTag("Asteroid");
}

Asteroid::~Asteroid() {
    delete asteroidSprite;
}

void Asteroid::Update(float dt) {
    asteroidPosition += asteroidVelocity * dt;
    asteroidSprite->setPosition(asteroidPosition);

    sf::Vector2u windowSize = window->getSize();
    if (asteroidPosition.x < 0)
        asteroidPosition.x = windowSize.x;
    else if (asteroidPosition.x > windowSize.x)
        asteroidPosition.x = 0;
    if (asteroidPosition.y < 0)
        asteroidPosition.y = windowSize.y;
    else if (asteroidPosition.y > windowSize.y)
        asteroidPosition.y = 0;

    asteroidSprite->setPosition(asteroidPosition);
}

void Asteroid::Draw(sf::RenderWindow* window) {
    window->draw(*asteroidSprite);
}
