#include <iostream>
#include "Game.h"

Game::Game(sf::RenderWindow* window) {
    this->window = window;

    player = new Player(window);
    asteroids = new Asteroids(window);
    ui = new UI("DS-DIGI.ttf", 30, sf::Color::White, sf::Vector2f(0, 0));
}

Game::~Game() {
    delete player;
    delete asteroids;
    delete ui;
}

void Game::Update(float dt) {
    player->Update(dt);
    player->DrawPlayer();

    asteroids->Update(dt);
    asteroids->Draw();

    ui->setText("Score " + std::to_string(score));
    ui->setPosition(sf::Vector2f(10, 10));
    ui->draw(window);

    ui->setText("Lives " + std::to_string(lives));
    ui->setPosition(sf::Vector2f(10, 35));
    ui->draw(window);
}




