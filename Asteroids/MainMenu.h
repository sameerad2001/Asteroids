#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Scene.h"
#include "SceneManager.h"

class MainMenu : public Scene, public EventListener {
public :
	MainMenu(sf::RenderWindow* window) ;
	~MainMenu() override;
	void Update(float dt) override;
	void ReceiveEvent(EventType type) override;
	void TransitionScene() override;

protected :
	UI* ui;
	sf::RenderWindow* window;
};