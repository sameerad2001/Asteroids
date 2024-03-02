#pragma once
#include <SFML/Graphics.hpp>
#include "EventSystem.h"
#include "UISystem.h"
#include "Scene.h"
#include "SceneManager.h"

class EndScreen : public Scene, public EventListener {
public:
	EndScreen(sf::RenderWindow* window, int score = 0);
	~EndScreen() override;
	void Update(float dt) override;
	void ReceiveEvent(EventType type) override;
	void TransitionScene() override;

protected:
	UI* ui;
	sf::RenderWindow* window;
	int score = 0;
};