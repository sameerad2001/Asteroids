#pragma once
#include <SFML/Graphics.hpp>

enum VolumeType {
	AABB,
	SPHERE
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

struct SphereVolume : public PhysicsVolume {
	SphereVolume(sf::Sprite* sprite) {
		volumeType = SPHERE;
		this->sprite = sprite;
	}
	float GetRadius() const { 
		sf::FloatRect bounds = sprite->getGlobalBounds();
		//float radius = std::sqrtf(bounds.width * bounds.width + bounds.height * bounds.height) / 2.0f;
		float radius = std::max(bounds.width, bounds.height) / 2.0f;
		return radius;
	}
	sf::Vector2f GetGlobalCenter() const { return sprite->getPosition(); }

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