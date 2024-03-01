#include "Game.h"
#include "LevelUI.h"

Game::Game(sf::RenderWindow* window) {
    this->window = window;
    engine = new Engine(window);
    EventEmitter::RegisterForEvent(FIRE, this);
    EventEmitter::RegisterForEvent(PLAYER_ASTEROID_COLLISION, this);
    EventEmitter::RegisterForEvent(BULLET_ASTEROID_COLLISION, this);

    // Initializing game objects
    player = new Player(window);
    engine->AddGameObject(player);

    levelUI = new LevelUI(this);
    engine->AddGameObject(levelUI);

    for (int i = 0; i < ASTEROID_POOL_SIZE; i++) {
        Asteroid* asteroid = new Asteroid(window);
        asteroid->SetIsActive(false);
        asteroidPool.push_back(asteroid);
        engine->AddGameObject(asteroid);
    }

    for (int i = 0; i < BULLET_POOL_SIZE; i++) {
        Bullet* bullet = new Bullet(window, sf::Vector2f(0, 0), sf::Vector2f(0, 0));
        bullet->SetIsActive(false);
        bulletPool.push_back(bullet);
        engine->AddGameObject(bullet);
    }
}

Game::~Game() {
    delete engine;
    EventEmitter::RemoveListner(this);
}

void Game::Update(float dt) {
    engine->Update(dt);
    engine->Draw();
    timeSinceLastBullet += dt;
    timeSinceDeath += dt;
    timeSinceLastAsteroid += dt;

    if (timeSinceLastAsteroid < ASTEROID_SPAWN_TIME) return;

    Asteroid* asteroid = SpawnAsteroid();
    if (asteroid) timeSinceLastAsteroid = 0;
}

void Game::TransitionScene()
{
    SceneManager* sceneManger = SceneManager::GetInstance();
    sceneManger->PopScene();
    return;
}

void Game::ReceiveEvent(const EventType eventType) {
    if (eventType == FIRE && timeSinceLastBullet > 1.0f / FIRE_RATE) {

        for (Bullet* bullet : bulletPool) {
            if (!bullet->GetIsActive()) {
                bullet->ResetBullet(player->GetCenter(), player->GetDirection());
                break;
            }
        }
        timeSinceLastBullet = 0;
    }
    if (eventType == PLAYER_ASTEROID_COLLISION && timeSinceDeath > AFTER_DEATH_GRACE_PERIOD) {
        lives--;
        timeSinceDeath = 0;
        player->SetPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2));
        player->SetVelocity(sf::Vector2f(0, 0));

        if (lives <= 0) { 
            isTransitioning = true;
            return;
        }
    }
    if (eventType == BULLET_ASTEROID_COLLISION) {
        score++;
    }
}

Asteroid* Game::SpawnAsteroid() {
    for (Asteroid* asteroid : asteroidPool) {
        if (!asteroid->GetIsActive()) {
            asteroid->ResetAsteroid();
            return asteroid;
        }
    }
    return nullptr;
}