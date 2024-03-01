#include <iostream>
#include "Game.h"
#include "LevelUI.h"

Game::Game(sf::RenderWindow* window) {
    this->window = window;
    engine = new Engine(window);
    EventEmitter::RegisterForEvent(FIRE, this);

    // Initializing game objects
    player = new Player(window);
    engine->AddGameObject(player);

    asteroid = new Asteroid(window);
    engine->AddGameObject(asteroid);

    levelUI = new LevelUI(this);
    engine->AddGameObject(levelUI);

    for (int i = 0; i < BULLET_POOL_SIZE; ++i) {
        Bullet* bullet = new Bullet(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0));
        bullet->SetIsActive(false);
        bulletPool.push_back(bullet);
        engine->AddGameObject(bullet);
    }
}

Game::~Game() {
    delete engine;
}

void Game::Update(float dt) {
    engine->Update(dt);
    engine->Draw();
    timeSinceLastBullet += dt;
}

void Game::ReceiveEvent(const EventType eventType) {
    if (eventType != FIRE || timeSinceLastBullet < 1.0f / FIRE_RATE) return;

    for (Bullet* bullet : bulletPool) {
        if (!bullet->GetIsActive()) {
            bullet->ResetBullet(player->GetCenter(), player->GetDirection());
            break;
        }
    }
    timeSinceLastBullet = 0;
}

