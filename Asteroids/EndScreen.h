#pragma once
#include <SFML/Graphics.hpp>
#include "UISystem.h"
#include "Scene.h"
#include "SceneManager.h"

class EndScreen : public Scene{
public:
	EndScreen(sf::RenderWindow* window, int score = 0);
	~EndScreen() override;
	void Update(float dt) override;
	void TransitionScene() override;

protected:
	UI* ui;
	sf::RenderWindow* window;
	int score = 0;
	float endScreenDisplayTime = 3; // Visible for <time> seconds
};