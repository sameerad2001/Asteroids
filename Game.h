#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "UISystem.h"
#include "Asteroids.h"

class Game
{
public :
    Game(sf::RenderWindow* window);
    ~Game();

    void Update(float dt);

protected :
    Player* player;
    Asteroids* asteroids;
    UI* ui;

    sf::RenderWindow* window;

    bool isGameOver = false;
    int score = 0;
    int lives = 3;
};