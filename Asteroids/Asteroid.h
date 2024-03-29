#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "GameObject.h"

enum AsteroidType {
	BIG = 3,
	MEDIUM = 2,
	SMALL = 1
};

extern std::unordered_map<AsteroidType, float> scaleFactors;

class Asteroid : public GameObject{
public :
	Asteroid(sf::RenderWindow* window, AsteroidType type = BIG);
	~Asteroid() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow* window) override;
	void OnCollision(GameObject* other) override {};
	void ResetAsteroid(AsteroidType type = (AsteroidType)0);
	void ResetAsteroid(const sf::Vector2f& position, const sf::Vector2f& velocity, AsteroidType type = (AsteroidType)0);
	
	AsteroidType GetAsteroidType()	const { return asteroidType; }
	sf::Vector2f GetPosition()		const { return asteroidPosition; }
	sf::Vector2f GetVelocity()		const { return asteroidVelocity; }

	void SetAsteroidType(const AsteroidType& type) { 
		asteroidType = type; 
		asteroidSprite->setScale(scaleFactors[type], scaleFactors[type]);
	}
	
protected :
	sf::RenderWindow* window;

	sf::Sprite* asteroidSprite;
	sf::Texture asteroidTexture;
	sf::Vector2f asteroidPosition; 
	sf::Vector2f asteroidVelocity;
	AsteroidType asteroidType;

	void InitializeAsteroid();
	sf::Vector2f GetRandomPosition() const;
	sf::Vector2f GetRandomVelocity() const;
};