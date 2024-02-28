#include <iostream>
#include "Game.h"

Game::Game(sf::RenderWindow* window) {
    player = new Player(window);

    AsteroidTexture.loadFromFile("Assets/Asteroid.png");
    Asteroid.setTexture(AsteroidTexture);

    this->window = window;
}

Game::~Game() {
    delete player;
}

void Game::Update(float dt) {
    player->MovePlayer(dt);
    player->DrawPlayer();

    //Asteroid.setPosition(400, 400);
    //float Rotation = 90.0f;
    //Asteroid.rotate(Rotation * dt);
    //window->draw(Asteroid);
}




