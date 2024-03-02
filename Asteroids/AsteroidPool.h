#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Asteroid.h"
#include "Engine.h"

class AsteroidPool {
public :
    AsteroidPool(sf::RenderWindow* window, Engine* engine);
    Asteroid* SpawnAsteroid(AsteroidType type = static_cast<AsteroidType>(0));
    Asteroid* SpawnAsteroid(const sf::Vector2f& position, const sf::Vector2f& velocity, AsteroidType type);
    void SplitAsteroid(Asteroid* asteroid);

private:
    std::vector<Asteroid*> asteroidPool;
    const int ASTEROID_POOL_SIZE = 30;
};