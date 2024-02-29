#pragma once
#include <SFML/Graphics.hpp>
#include "EventSystem.h"
#include "GameObject.h"

class Player : public EventListener, public GameObject {
public :
    Player(sf::RenderWindow* window);
    ~Player() override;
    void Update(float dt) override;
    void Draw() override;
    void OnCollisionBegin(GameObject* other) override {};
    void ReceiveEvent(const EventType eventType) override;
    sf::Vector2f GetPosition() const { return playerPosition; };
    sf::Vector2f GetDirection() const { return playerDirection; };
    sf::Vector2f GetCenter() const { return playerPosition + (playerSprite.getScale() * 0.5f); }

protected :
    sf::Sprite playerSprite;
    sf::Texture playerTexture;
    sf::Vector2f playerPosition;
    sf::Vector2f playerVelocity;
    sf::Vector2f playerDirection;

    sf::RenderWindow* window;

    float dt;

    const int PLAYER_SPEED = 200;
    const int TURN_SPEED = 3500;
    const int SPEED_LOSS_FACTOR = 0.5;
};