#pragma once
#include "PhysicsBody.h"

class GameObject {
public :
	virtual ~GameObject() {
		if (!physicsBody) return;
		delete physicsBody;
		physicsBody = nullptr;
	};
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	virtual void OnCollision(GameObject* other) = 0;

	void SetIsActive(const bool& val) { isActive = val; }
	bool GetIsActive() const { return isActive; }

	PhysicsBody* GetPhysicsBody() const { return physicsBody; }
	void SetPhysicsBody(PhysicsBody* body) { physicsBody = body; }

	void SetTag(std::string tag) { this->tag = tag; }
	std::string GetTag() const { return tag; }

private :
	bool isActive = true;
	PhysicsBody* physicsBody;
	std::string tag = "IDK";
};