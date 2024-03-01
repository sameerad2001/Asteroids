#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Scene.h"
#include "Game.h"
#include "MainMenu.h"

// These are currently coupled to the game
enum SceneType {
	MAIN_MENU,
	GAME
};

class SceneManager {
public:
    static SceneManager* GetInstance(sf::RenderWindow* window);
    void Destroy();

    void Update(float dt);
    void ChangeScene(SceneType sceneType);

private:
    SceneManager(sf::RenderWindow* window);
    ~SceneManager() {}

    static SceneManager* instance;
    Scene* currentScene;
    sf::RenderWindow* window;
};