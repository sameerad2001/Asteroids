#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Asteroids : public GameObject{
public :
	Asteroids(sf::RenderWindow* window);
	~Asteroids() override {};
	void Update(float dt) override;
	void Draw() override;
	void OnCollisionBegin() override {};

protected :
	sf::RenderWindow* window;

	sf::Sprite asteroidSprite;
	sf::Texture asteroidTexture;
	sf::Vector2f asteroidPosition; 
	sf::Vector2f asteroidVelocity;
};