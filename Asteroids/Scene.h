#pragma once

// NOTE :
// Scenes transitions take place in the subsequent frame after the "isTransitioning" bool is set.
// If transition occurs during the same frame there will be issues with dangling pointers 
// ... becaues Pop deletes the current scene.
class Scene {
public :
	virtual ~Scene() = 0 {};
	virtual void Update(float dt) = 0;
	virtual void TransitionScene() = 0; // Scene transition code goes here
	bool isTransitioning = false;
};