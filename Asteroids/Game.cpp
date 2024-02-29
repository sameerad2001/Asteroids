#include <iostream>
#include "Game.h"
#include "LevelUI.h"

Game::Game(sf::RenderWindow* window) {
    this->window = window;

    engine = new Engine();

    // Initializing game objects
    player = new Player(window);
    engine->AddGameObject(player);

    asteroids = new Asteroids(window);
    engine->AddGameObject(asteroids);

    levelUI = new LevelUI(window, this);
    engine->AddGameObject(levelUI);
}

Game::~Game() {
    delete engine;
}

void Game::Update(float dt) {
    engine->Update(dt);
    engine->Draw();
}




