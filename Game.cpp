#include <iostream>
#include "Game.h"
#include "Utility.h"

Game::Game(sf::RenderWindow* window) {
    PlayerTexture.loadFromFile("Assets/Ship.png");
    Player.setTexture(PlayerTexture);
    playerPosition  = sf::Vector2f(400, 400);
    playerVelocity  = sf::Vector2f(0, 0);
    playerDirection = sf::Vector2f(0, -1);

    AsteroidTexture.loadFromFile("Assets/Asteroid.png");
    Asteroid.setTexture(AsteroidTexture);

    this->window = window;
    EventEmitter::RegisterForEvent(THRUST, this);
    EventEmitter::RegisterForEvent(TURN_LEFT, this);
    EventEmitter::RegisterForEvent(TURN_RIGHT, this);
    EventEmitter::RegisterForEvent(REVERSE, this);
}

void Game::Update(float dt) {
    this->dt = dt;

    playerPosition += playerVelocity * dt;
    if (VectorMagnitude(playerVelocity) > 0.05) {
        playerVelocity = Lerp(playerVelocity, sf::Vector2f(0, 0), dt * SPEED_LOSS_FACTOR);
    }
    Player.setPosition(playerPosition);
    float angle = std::atan2(playerDirection.y, playerDirection.x) * (180.0f / 3.14);
    Player.setRotation(angle);
    window->draw(Player);

    //Asteroid.setPosition(400, 400);
    //float Rotation = 90.0f;
    //Asteroid.rotate(Rotation * dt);
    //window->draw(Asteroid);
}


void Game::ReceiveEvent(const EventType eventType) {
    switch (eventType) {
    case THRUST:
        playerVelocity = sf::Vector2f(playerDirection.x * PLAYER_SPEED, playerDirection.y * PLAYER_SPEED);
        break;
    case REVERSE:
        playerVelocity = sf::Vector2f(-playerDirection.x * PLAYER_SPEED, -playerDirection.y * PLAYER_SPEED);
        break;
    case TURN_LEFT:
        playerDirection = RotateVector(playerDirection, -TURN_ANGLE * dt);
        break;
    case TURN_RIGHT:
        playerDirection = RotateVector(playerDirection, TURN_ANGLE * dt);
        break;
    default:
        break;
    }
}
