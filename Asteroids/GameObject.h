#pragma once

class GameObject {
public :
	virtual ~GameObject() = 0 { /*Do nothing*/ };
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	virtual void OnCollisionBegin(GameObject* other) = 0;

	void SetIsActive(const bool& val) { isActive = val; }
	bool GetIsActive() const { return isActive; }

private :
	bool isActive = true;
};