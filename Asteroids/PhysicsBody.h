#pragma once
#include <SFML/Graphics.hpp>

// Can be extended to add spheres or OBBs
enum VolumeType {
	AABB
};

struct PhysicsVolume {
	VolumeType volumeType;
};

struct AABBVolume : public PhysicsVolume{
	AABBVolume(sf::Sprite* sprite) {
		volumeType = AABB;
		this->sprite = sprite;
	}
	sf::FloatRect GetGlobalBound() const { return sprite->getGlobalBounds(); }

private:
	sf::Sprite* sprite;
};

class PhysicsBody {
public :
	~PhysicsBody() {
		if (physicsVolume)
			delete(physicsVolume);
	}
	void SetPhysicsVolume(PhysicsVolume* volume) { physicsVolume = volume; }
	PhysicsVolume* GetPhysicsVolume() const { return physicsVolume; }

protected :
	PhysicsVolume* physicsVolume;
};