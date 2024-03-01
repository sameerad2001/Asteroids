#include "Player.h"
#include "Utility.h"

Player::Player(sf::RenderWindow* window) {
    this->window = window;
    playerTexture.loadFromFile("Assets/Ship.png");
    playerSprite = new sf::Sprite();
    playerSprite->setTexture(playerTexture);
    playerSprite->setOrigin(playerTexture.getSize().x / 2.0f, playerTexture.getSize().y / 2.0f);
    playerPosition = sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2);
    playerVelocity = sf::Vector2f(0, 0);
    playerDirection = sf::Vector2f(0, -1);

    PhysicsBody* physicsBody = new PhysicsBody();
    PhysicsVolume* physicVolume = new AABBVolume(playerSprite);
    physicsBody->SetPhysicsVolume(physicVolume);
    this->SetPhysicsBody(physicsBody);

    EventEmitter::RegisterForEvent(THRUST, this);
    EventEmitter::RegisterForEvent(TURN_LEFT, this);
    EventEmitter::RegisterForEvent(TURN_RIGHT, this);
    EventEmitter::RegisterForEvent(REVERSE, this);

    this->SetTag("Player");
}

Player::~Player() {
    EventEmitter::RemoveListner(this);
    delete playerSprite;
}

void Player::Update(float dt) {
    this->dt = dt;

    playerPosition += playerVelocity * dt;
    if (playerPosition.x < 0)
        playerPosition.x = window->getSize().x;
    else if (playerPosition.x > window->getSize().x)
        playerPosition.x = 0;
    if (playerPosition.y < 0)
        playerPosition.y = window->getSize().y;
    else if (playerPosition.y > window->getSize().y)
        playerPosition.y = 0;

    if (VectorMagnitude(playerVelocity) > 0.05)
        playerVelocity = Lerp(playerVelocity, sf::Vector2f(0, 0), dt * SPEED_LOSS_FACTOR);

    playerSprite->setPosition(playerPosition);
    float angle = std::atan2(playerDirection.y, playerDirection.x) * (180.0f / 3.14);
    playerSprite->setRotation(angle);
}

void Player::Draw(sf::RenderWindow* window) {
    window->draw(*playerSprite);
}

void Player::ReceiveEvent(const EventType eventType) {
    switch (eventType) {
    case THRUST:
        playerVelocity = sf::Vector2f(playerDirection.x * PLAYER_SPEED, playerDirection.y * PLAYER_SPEED);
        break;
    case REVERSE:
        // According to the design specifications the player can only move forward
        //playerVelocity = sf::Vector2f(-playerDirection.x * PLAYER_SPEED, -playerDirection.y * PLAYER_SPEED);
        break;
    case TURN_LEFT:
        playerDirection = RotateVector(playerDirection, -TURN_SPEED * dt);
        break;
    case TURN_RIGHT:
        playerDirection = RotateVector(playerDirection, TURN_SPEED * dt);
        break;
    default:
        break;
    }
}

void Player::OnCollision(GameObject* other) {
    if (other->GetTag() == "Asteroid") {
        EventEmitter::EmitEvent(PLAYER_ASTEROID_COLLISION);
    }
}