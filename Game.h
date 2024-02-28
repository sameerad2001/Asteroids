#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
public :
    Game(sf::RenderWindow* window);
    ~Game();

    void Update(float dt);

protected :
    sf::RenderWindow* window;
    Player* player;
    sf::Sprite Asteroid;
    sf::Texture AsteroidTexture;

    bool isGameOver = false;
};