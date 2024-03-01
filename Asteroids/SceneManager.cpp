#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::~SceneManager() {
    while (!sceneStack.empty()) {
        delete sceneStack.top();
        sceneStack.pop();
    }
}

SceneManager* SceneManager::GetInstance() {
    if (!instance)
        instance = new SceneManager();
    return instance;
}

void SceneManager::Destroy()
{
    if (!instance)  return;
    delete instance;
    instance = nullptr;
}

void SceneManager::PushScene(Scene* scene) {
    sceneStack.push(scene);
}

void SceneManager::PopScene() {
    if (sceneStack.empty()) return;
    delete sceneStack.top();
    sceneStack.pop();
    sceneStack.top()->isTransitioning = false;
}

void SceneManager::ChangeScene(Scene* scene) {
    PopScene();
    PushScene(scene);
}

void SceneManager::Update(float dt) {
    if (sceneStack.empty()) return;

    // NOTE :
    // Scenes transitions take place in the subsequent frame after the "isTransitioning" bool is set.
    // If transition occurs during the same frame there will be issues with dangling pointers 
    // ... becaues Pop deletes the current scene.
    if (sceneStack.top()->isTransitioning) {
        sceneStack.top()->TransitionScene();
        return;
    }
    
    sceneStack.top()->Update(dt);
}
