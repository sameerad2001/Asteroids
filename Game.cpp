#include <iostream>
#include "Game.h"
#include "Utility.h"

Game::Game(sf::RenderWindow* window) {
    PlayerTexture.loadFromFile("Assets/Ship.png");
    Player.setTexture(PlayerTexture);
    playerPosition = sf::Vector2f(400, 400);
    playerVelocity = sf::Vector2f(0, 0);

    AsteroidTexture.loadFromFile("Assets/Asteroid.png");
    Asteroid.setTexture(AsteroidTexture);

    this->window = window;
    EventEmitter::RegisterForEvent(THRUST, this);
}

void Game::Update(float dt) {
    playerPosition += playerVelocity * dt;
    playerVelocity = Lerp(playerVelocity, sf::Vector2f(0, 0), dt * SPEED_LOSS_FACTOR);
    Player.setPosition(playerPosition);
    window->draw(Player);


    // Asteroid spins in the center of the screen
    Asteroid.setPosition(400, 400);
    float Rotation = 90.0f;
    Asteroid.rotate(Rotation * dt);
    window->draw(Asteroid);
}


void Game::ReceiveEvent(const EventType eventType) {
    switch (eventType)
    {
    case THRUST: 
        playerVelocity = sf::Vector2f(0, PLAYER_SPEED);
        break;    
    default:
        break;
    }
}
