#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include "Scene.h"

class SceneManager {
public:
    static SceneManager* GetInstance();
    void Destroy();

    void PushScene(Scene* scene);
    void PopScene();
    void ChangeScene(Scene* scene);
    void Update(float dt);

private:
    SceneManager() {};
    ~SceneManager();

    std::stack<Scene*> sceneStack;
    static SceneManager* instance;
};
