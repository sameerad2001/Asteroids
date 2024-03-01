#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "SceneManager.h"

class MainMenu : public Scene, public EventListener {
public :
	MainMenu(sf::RenderWindow* window) ;
	~MainMenu();
	void Update(float dt) override;
	void ReceiveEvent(EventType type) override;

protected :
	UI* ui;
	sf::RenderWindow* window;
};