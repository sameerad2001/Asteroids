#pragma once
#include <vector>
#include "GameObject.h"

class Engine {
public:
    Engine(sf::RenderWindow* window);
    ~Engine();

    void AddGameObject(GameObject* gameObject);
    void Update(float dt);
    void Draw();
    void CheckCollisions();

private:
    bool IsColliding(GameObject* obj1, GameObject* obj2);
    bool CheckAABBCollision(const AABBVolume* aabb1, const AABBVolume* aabb2);

private:
    std::vector<GameObject*> gameObjects;
    sf::RenderWindow* window;
};
