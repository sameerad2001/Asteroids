#include "AsteroidPool.h"

AsteroidPool::AsteroidPool(sf::RenderWindow* window, Engine* engine)
{
    for (int i = 0; i < ASTEROID_POOL_SIZE; i++) {
        Asteroid* asteroid = new Asteroid(window);
        asteroid->SetIsActive(false);
        asteroidPool.push_back(asteroid);
        engine->AddGameObject(asteroid);
    }
}

Asteroid* AsteroidPool::SpawnAsteroid(AsteroidType type)
{
    for (Asteroid* asteroid : asteroidPool) {
        if (!asteroid->GetIsActive()) {
            asteroid->ResetAsteroid(type);
            return asteroid;
        }
    }
    return nullptr;
}

Asteroid* AsteroidPool::SpawnAsteroid(const sf::Vector2f& position, const sf::Vector2f& velocity, AsteroidType type) {
    for (Asteroid* asteroid : asteroidPool) {
        if (!asteroid->GetIsActive()) {
            asteroid->ResetAsteroid(position, velocity, type);
            return asteroid;
        }
    }
    return nullptr;
}

void AsteroidPool::SplitAsteroid(Asteroid* asteroid)
{
    if (!asteroid || asteroid->GetAsteroidType() == SMALL)
        return;

    AsteroidType currentType = asteroid->GetAsteroidType();
    AsteroidType newType = static_cast<AsteroidType>(static_cast<int>(currentType) - 1);

    sf::Vector2f position = asteroid->GetPosition();
    sf::Vector2f velocity = asteroid->GetVelocity();

    asteroid->SetAsteroidType(newType);
    Asteroid* newAsteroid1 = SpawnAsteroid(position, -1.0f * velocity, newType);
}

