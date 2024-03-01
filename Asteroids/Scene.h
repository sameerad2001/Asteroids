#pragma once

class Scene {
public :
	virtual ~Scene() = 0 {};
	virtual void Update(float dt) = 0;
};