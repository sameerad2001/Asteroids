#pragma once
#include <vector>
#include "GameObject.h"

class Engine {
public :
	~Engine() {
		for (auto gameObject : gameObjects) {
			delete gameObject;
			gameObject = nullptr;
		}
		gameObjects.clear();
	}

	void AddGameObject(GameObject* gameObject) {
		gameObjects.push_back(gameObject);
	}

	void Update(float dt) {
		for (auto gameObject : gameObjects) {
			if (!gameObject->GetIsActive()) continue;
			gameObject->Update(dt);
		}
	}

	void Draw() {
		for (auto gameObject : gameObjects) {
			if (!gameObject->GetIsActive()) continue;
			gameObject->Draw();
		}
	}

	// TODO : Check collisions

private :
	std::vector<GameObject*> gameObjects;
};