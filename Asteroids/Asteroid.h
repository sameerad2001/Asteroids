#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Asteroid : public GameObject{
public :
	Asteroid(sf::RenderWindow* window);
	~Asteroid() override;
	void Update(float dt) override;
	void Draw() override;
	void OnCollision(GameObject* other) override {};

protected :
	sf::RenderWindow* window;

	sf::Sprite* asteroidSprite;
	sf::Texture asteroidTexture;
	sf::Vector2f asteroidPosition; 
	sf::Vector2f asteroidVelocity;
};