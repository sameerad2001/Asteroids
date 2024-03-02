#include "MainMenu.h"
#include "SceneManager.h"
#include "InputSystem.h"

int main()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Asteroids!");
    sf::Clock GameClock;

    SceneManager* sceneManager = SceneManager::GetInstance();
    sceneManager->PushScene(new MainMenu(window));

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            InputSystem::ReceiveEvent(event);
        }
        InputSystem::Update();

        sf::Time dt = GameClock.restart();

        window->clear();
        sceneManager->Update(dt.asSeconds());
        window->display();
    }
    sceneManager->Destroy();
    delete window;
    return 0;
}