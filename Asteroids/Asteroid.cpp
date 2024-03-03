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
    InitializeAsteroid();
}

Asteroid::~Asteroid() {
    delete asteroidSprite;
}

void Asteroid::Update(float dt) {
    asteroidPosition += asteroidVelocity * dt;
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

void Asteroid::ResetAsteroid(AsteroidType type) {
    if (type == 0)
        type = static_cast<AsteroidType>(std::rand() % 3 + 1);

    asteroidType = type;
    InitializeAsteroid();
    SetIsActive(true);
}

void Asteroid::ResetAsteroid(const sf::Vector2f& position, const sf::Vector2f& velocity, AsteroidType type) {
    if (type == 0)
        type = static_cast<AsteroidType>(std::rand() % 3 + 1);

    asteroidType = type;
    InitializeAsteroid();
    asteroidPosition = position;
    asteroidVelocity = velocity;
    SetIsActive(true);
}

void Asteroid::InitializeAsteroid() {
    asteroidTexture.loadFromFile("Assets/Asteroid.png");
    asteroidSprite = new sf::Sprite();
    asteroidSprite->setTexture(asteroidTexture);
    asteroidSprite->setOrigin(asteroidTexture.getSize().x / 2.0f, asteroidTexture.getSize().y / 2.0f);
    asteroidSprite->setScale(scaleFactors[asteroidType], scaleFactors[asteroidType]);
    asteroidPosition = GetRandomPosition();
    asteroidVelocity = GetRandomVelocity();
    PhysicsBody* physicsBody = new PhysicsBody();
    PhysicsVolume* physicVolume = new SphereVolume(asteroidSprite);
    physicsBody->SetPhysicsVolume(physicVolume);
    this->SetPhysicsBody(physicsBody);
    this->SetTag("Asteroid");
}


sf::Vector2f Asteroid::GetRandomPosition() const {
    float posX, posY;
    sf::Vector2u windowSize = window->getSize();
    if (std::rand() % 2 == 0) {
        // Left/Right
        posX = std::rand() % 2 == 0 ? -((int)asteroidTexture.getSize().x) : windowSize.x;
        posY = std::rand() % windowSize.y;
    }
    else {
        // Top/Bottom
        posX = std::rand() % windowSize.x;
        posY = std::rand() % 2 == 0 ? -((int)asteroidTexture.getSize().y) : windowSize.y;
    }

    sf::Vector2f position = sf::Vector2f(posX, posY);
    return position;
}

sf::Vector2f Asteroid::GetRandomVelocity() const {
    float angle = static_cast<float>(std::rand() % 360);
    float radians = angle * (3.14 / 180.0f);
    static const float SPEED = 100.0f;
    float velX = std::cos(radians) * SPEED;
    float velY = std::sin(radians) * SPEED;
    return sf::Vector2f(velX, velY);
}