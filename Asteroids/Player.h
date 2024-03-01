#pragma once
#include <SFML/Graphics.hpp>
#include "EventSystem.h"
#include "GameObject.h"
#include "PhysicsBody.h"

class Player : public EventListener, public GameObject {
public :
    Player(sf::RenderWindow* window);
    ~Player() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow* window) override;
    void OnCollision(GameObject* other) override;
    void ReceiveEvent(const EventType eventType) override;
    sf::Vector2f GetPosition() const { return playerPosition; };
    sf::Vector2f GetDirection() const { return playerDirection; };
    sf::Vector2f GetCenter() const { return playerPosition + (playerSprite->getScale() * 0.5f); }
    void SetPosition(const sf::Vector2f& newPosition) { playerPosition = newPosition; };
    void SetVelocity(const sf::Vector2f& newVelocity) { playerVelocity = newVelocity; };

protected :
    sf::Sprite* playerSprite;
    sf::Texture playerTexture;
    sf::Vector2f playerPosition;
    sf::Vector2f playerVelocity;
    sf::Vector2f playerDirection;

    sf::RenderWindow* window;

    float dt;

    const int PLAYER_SPEED = 200;
    const int TURN_SPEED = 3500;
    const float SPEED_LOSS_FACTOR = 0.5;
};