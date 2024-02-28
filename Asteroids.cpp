#include "Asteroids.h"

Asteroids::Asteroids(sf::RenderWindow* window) {
	this->window = window;

    asteroidTexture.loadFromFile("Assets/Asteroid.png");
    asteroidSprite.setTexture(asteroidTexture);
}

void Asteroids::Update(float dt) {
    asteroidSprite.setPosition(400, 400);
    float Rotation = 90.0f;
    asteroidSprite.rotate(Rotation * dt);
}

void Asteroids::Draw() {
    window->draw(asteroidSprite);
}