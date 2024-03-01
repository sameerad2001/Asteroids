#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

enum AsteroidType {
	BIG = 2,
	SMALL = 1
};

class Asteroid : public GameObject{
public :
	Asteroid(sf::RenderWindow* window, AsteroidType type = BIG);
	~Asteroid() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow* window) override;
	void OnCollision(GameObject* other) override {};

	void SetAsteroidType(const AsteroidType& type) { 
		asteroidType = type; 
		asteroidSprite->setScale(type, type);
	}
	AsteroidType GetAsteroidType() const { return asteroidType; }

protected :
	sf::RenderWindow* window;

	sf::Sprite* asteroidSprite;
	sf::Texture asteroidTexture;
	sf::Vector2f asteroidPosition; 
	sf::Vector2f asteroidVelocity;

	AsteroidType asteroidType;
};