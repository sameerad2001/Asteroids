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
        if (!gameObject) continue;
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

    switch (volume1->volumeType) {
    case AABB :
        return AABBCollisionFunctions[volume2->volumeType](volume1, volume2);
        break;
    case SPHERE :
        return SphereCollisionFunctions[volume2->volumeType](volume1, volume2);
        break;
    default :
        return false;
    }
    
    return false;
}

bool Engine::AABBvsAABBCollision(const AABBVolume* aabb1, const AABBVolume* aabb2) {
    return aabb1->GetGlobalBound().intersects(aabb2->GetGlobalBound());
}

bool Engine::AABBvsSphereCollision(const AABBVolume* aabb, const SphereVolume* sphere) {
    sf::Vector2f sphereCenter = sphere->GetGlobalCenter();
    sf::FloatRect aabbRect = aabb->GetGlobalBound();

    // Find the point in the AABB closest to the sphere
    float closestX = std::clamp(sphereCenter.x, aabbRect.left, aabbRect.left + aabbRect.width);
    float closestY = std::clamp(sphereCenter.y, aabbRect.top, aabbRect.top + aabbRect.height);

    // Calculate the distance between the sphere center and the closest point in the AABB
    float distanceX = sphereCenter.x - closestX;
    float distanceY = sphereCenter.y - closestY;

    // If the distance is less than the sphere radius, they are colliding
    float distanceSquared = distanceX * distanceX + distanceY * distanceY;
    float radiusSquared = static_cast<float>(sphere->GetRadius()) * static_cast<float>(sphere->GetRadius());

    return distanceSquared <= radiusSquared;
}

bool Engine::SpherevsSphereCollision(const SphereVolume* sphere1, const SphereVolume* sphere2)
{
    sf::Vector2f center1 = sphere1->GetGlobalCenter();
    sf::Vector2f center2 = sphere2->GetGlobalCenter();
    float radius1 = static_cast<float>(sphere1->GetRadius());
    float radius2 = static_cast<float>(sphere2->GetRadius());

    // Calculate the distance between the centers of the spheres
    float distance = std::sqrt(std::pow(center2.x - center1.x, 2) + std::pow(center2.y - center1.y, 2));

    return distance <= (radius1 + radius2);
}

std::unordered_map<VolumeType, CollisionDetectionFuntion> Engine::AABBCollisionFunctions = {
    std::make_pair(AABB,
    [](const PhysicsVolume* vol1, const PhysicsVolume* vol2) -> bool {
        return Engine::AABBvsAABBCollision(static_cast<const AABBVolume*>(vol1), static_cast<const AABBVolume*>(vol2));
    }),

    std::make_pair(SPHERE,
    [](const PhysicsVolume* vol1, const PhysicsVolume* vol2) -> bool {
        return AABBvsSphereCollision(static_cast<const AABBVolume*>(vol1), static_cast<const SphereVolume*>(vol2));
    })
};

std::unordered_map<VolumeType, CollisionDetectionFuntion> Engine::SphereCollisionFunctions = {
    std::make_pair(AABB,
    [](const PhysicsVolume* vol1, const PhysicsVolume* vol2) -> bool {
        return Engine::AABBvsSphereCollision(static_cast<const AABBVolume*>(vol2), static_cast<const SphereVolume*>(vol1));
    }),

    std::make_pair(SPHERE,
    [](const PhysicsVolume* vol1, const PhysicsVolume* vol2) -> bool {
        return SpherevsSphereCollision(static_cast<const SphereVolume*>(vol1), static_cast<const SphereVolume*>(vol2));
    })
};
