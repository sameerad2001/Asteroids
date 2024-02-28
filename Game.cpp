#include <iostream>
#include "Game.h"

Game::Game(sf::RenderWindow* window) {
    this->window = window;

    player = new Player(window);
    ui = new UI("DS-DIGI.ttf", 30, sf::Color::White, sf::Vector2f(0, 0));

    AsteroidTexture.loadFromFile("Assets/Asteroid.png");
    Asteroid.setTexture(AsteroidTexture);
}

Game::~Game() {
    delete player;
}

void Game::Update(float dt) {
    player->MovePlayer(dt);
    player->DrawPlayer();

    ui->setText("Score " + std::to_string(score));
    ui->setPosition(sf::Vector2f(10, 10));
    ui->draw(window);

    ui->setText("Lives " + std::to_string(lives));
    ui->setPosition(sf::Vector2f(10, 35));
    ui->draw(window);

    //Asteroid.setPosition(400, 400);
    //float Rotation = 90.0f;
    //Asteroid.rotate(Rotation * dt);
    //window->draw(Asteroid);
}




