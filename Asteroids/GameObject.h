#pragma once

class GameObject {
public :
	virtual ~GameObject() = 0 { /*Do nothing*/ };
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	virtual void OnCollisionBegin() = 0;
};