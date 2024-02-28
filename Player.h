#pragma once
#include <SFML/Graphics.hpp>
#include "EventSystem.h"

class Player : public EventListener {
public :
    Player(sf::RenderWindow* window);
    ~Player();
    void MovePlayer(float dt);
    void DrawPlayer();
    void ReceiveEvent(const EventType eventType) override;

protected :
    sf::Sprite playerSprite;
    sf::Texture playerTexture;
    sf::Vector2f playerPosition;
    sf::Vector2f playerVelocity;
    sf::Vector2f playerDirection;

    sf::RenderWindow* window;

    float dt;

    const int PLAYER_SPEED = 200;
    const int TURN_SPEED = 1500;
    const int SPEED_LOSS_FACTOR = 0.5;
};