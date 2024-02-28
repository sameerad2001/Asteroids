#pragma once
#include <SFML/Graphics.hpp>
#include "EventSystem.h"

class Game : public EventListener 
{
public :
    Game(sf::RenderWindow* window);
	~Game() {
        EventEmitter::RemoveListner(this);
    }

    void Update(float dt);
    void ReceiveEvent(const EventType eventType) override;

protected :
    sf::RenderWindow* window;

    sf::Sprite Asteroid;
    sf::Texture AsteroidTexture;

    sf::Sprite Player;
    sf::Texture PlayerTexture;
    sf::Vector2f playerPosition;
    sf::Vector2f playerVelocity;
    sf::Vector2f playerDirection;
    const int PLAYER_SPEED = 150;
    const int TURN_ANGLE = 1000;
    const int SPEED_LOSS_FACTOR = 0.5;

    bool isGameOver = false;
    float dt;
};