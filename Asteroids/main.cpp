#include "Game.h"
#include "InputSystem.h"

int main()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1024, 768), "LHG Code Exercise");
    sf::Clock GameClock;

    Game asteroids(window);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            InputSystem::UpdateInputSystem(event);
        }
        sf::Time dt = GameClock.restart();

        window->clear();
        asteroids.Update(dt.asSeconds());
        window->display();
    }
    
    delete window;
    return 0;
}