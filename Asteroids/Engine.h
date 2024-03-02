#pragma once
#include <algorithm>
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
    bool AABBvsAABBCollision(const AABBVolume* aabb1, const AABBVolume* aabb2);
    bool AABBvsSphereCollision(const AABBVolume* aabb, const SphereVolume* sphere);
    bool SpherevsSphereCollision(const SphereVolume* sphere1, const SphereVolume* sphere2);

    std::vector<GameObject*> gameObjects;
    sf::RenderWindow* window;
};
