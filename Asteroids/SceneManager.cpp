#include "SceneManager.h"

SceneManager* SceneManager::instance;

SceneManager::SceneManager(sf::RenderWindow* window) {
    this->window = window;
    this->currentScene = nullptr;
}

SceneManager* SceneManager::GetInstance(sf::RenderWindow* window) {
    if (!instance)
        instance = new SceneManager(window);
    return instance;
}

void SceneManager::Destroy() {
    delete instance;
    instance = nullptr;
}

void SceneManager::Update(float dt) {
    if (!currentScene) return;
    currentScene->Update(dt);
}

void SceneManager::ChangeScene(SceneType sceneType) {
    if (currentScene)
        delete currentScene;

    switch (sceneType) {
    case GAME:
        currentScene = new Game(window);
        break;
    case MAIN_MENU :
        currentScene = new MainMenu(window);
        break;
        break;
    default:
        break;
    }
}