#include "Engine.h"

Engine::Engine(sf::RenderWindow* window) {
    this->window = window;
}

Engine::~Engine() {
    for (auto gameObject : gameObjects) {
        delete gameObject;
        gameObject = nullptr;
    }
    gameObjects.clear();
}

void Engine::AddGameObject(GameObject* gameObject) {
    gameObjects.push_back(gameObject);
}

void Engine::Update(float dt) {
    for (auto gameObject : gameObjects) {
        if (!gameObject) continue;
        if (!gameObject->GetIsActive()) continue;
        gameObject->Update(dt);
    }
    CheckCollisions();
}

void Engine::Draw() {
    for (auto gameObject : gameObjects) {
        if (!gameObject->GetIsActive()) continue;
        gameObject->Draw(window);
    }
}

void Engine::CheckCollisions() {
    for (int i = 0; i < gameObjects.size() - 1; i++) {
        if (!gameObjects[i]) continue;
        if (!gameObjects[i]->GetIsActive() || !gameObjects[i]->GetPhysicsBody()) continue;

        for (int j = i + 1; j < gameObjects.size(); j++) {
            if (!gameObjects[j]) continue;
            if (!gameObjects[j]->GetIsActive() || !gameObjects[j]->GetPhysicsBody()) continue;

            if (IsColliding(gameObjects[i], gameObjects[j])) {
                gameObjects[i]->OnCollision(gameObjects[j]);
                gameObjects[j]->OnCollision(gameObjects[i]);
            }
        }
    }
}

bool Engine::IsColliding(GameObject* obj1, GameObject* obj2) {
    PhysicsVolume* volume1 = obj1->GetPhysicsBody() ? obj1->GetPhysicsBody()->GetPhysicsVolume() : nullptr;
    PhysicsVolume* volume2 = obj2->GetPhysicsBody() ? obj2->GetPhysicsBody()->GetPhysicsVolume() : nullptr;

    if (!volume1 || !volume2) return false;

    if (volume1->volumeType == AABB) {
        switch (volume2->volumeType) {
        case AABB:
            return CheckAABBCollision(static_cast<AABBVolume*>(volume1), static_cast<AABBVolume*>(volume2));

        default:
            return false;
        }
    }
    // else other volume types

    return false;
}

bool Engine::CheckAABBCollision(const AABBVolume* aabb1, const AABBVolume* aabb2) {
    return aabb1->GetGlobalBound().intersects(aabb2->GetGlobalBound());
}
