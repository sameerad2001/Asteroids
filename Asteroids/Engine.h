#pragma once
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <vector>
#include "GameObject.h"

using CollisionDetectionFuntion = std::function<bool(const PhysicsVolume*, const PhysicsVolume*)>;

class Engine {
public:
    Engine(sf::RenderWindow* window);
    ~Engine();

    void AddGameObject(GameObject* gameObject);
    void Update(float dt);
    void Draw();
    void CheckCollisions();

private:
    static bool IsColliding(GameObject* obj1, GameObject* obj2);
    static bool AABBvsAABBCollision(const AABBVolume* aabb1, const AABBVolume* aabb2);
    static bool AABBvsSphereCollision(const AABBVolume* aabb, const SphereVolume* sphere);
    static bool SpherevsSphereCollision(const SphereVolume* sphere1, const SphereVolume* sphere2);

    std::vector<GameObject*> gameObjects;
    sf::RenderWindow* window;
    static std::unordered_map<VolumeType, CollisionDetectionFuntion> AABBCollisionFunctions;
    static std::unordered_map<VolumeType, CollisionDetectionFuntion> SphereCollisionFunctions;
};
