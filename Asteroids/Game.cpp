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

    for (int i = 0; i < BULLET_POOL_SIZE; ++i) {
        Bullet* bullet = new Bullet(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0));
        bullet->SetIsActive(false);
        bulletPool.push_back(bullet);
        engine->AddGameObject(bullet);
    }

    EventEmitter::RegisterForEvent(FIRE, this);
}

Game::~Game() {
    delete engine;
}

void Game::Update(float dt) {
    engine->Update(dt);
    engine->Draw();
}

void Game::ReceiveEvent(const EventType eventType) {
    if (eventType != FIRE) return;

    for (Bullet* bullet : bulletPool) {
        if (!bullet->GetIsActive()) {
            bullet->ResetBullet(player->GetPosition(), player->GetDirection());
            break;
        }
    }
}

