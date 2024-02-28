#pragma once
#include <SFML/Graphics.hpp>

class Asteroids {
public :
	Asteroids(sf::RenderWindow* window);
	~Asteroids();
	void Update(float dt);
	void Draw();

protected :
	sf::Sprite asteroidSprite;
	sf::Texture asteroidTexture;

	sf::RenderWindow* window;
};