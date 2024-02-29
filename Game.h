#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "UISystem.h"
#include "Asteroids.h"
#include "Engine.h"

class LevelUI;
class Game
{
public :
    Game(sf::RenderWindow* window);
    ~Game();

    void Update(float dt);

    int GetScore() const { return score; };
    int GetLives() const { return lives; };

protected :
    Player* player;
    Asteroids* asteroids;
    LevelUI* levelUI;
    //UI* ui;

    Engine* engine;

    sf::RenderWindow* window;

    bool isGameOver = false;
    int score = 0;
    int lives = 3;
};