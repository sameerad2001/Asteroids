#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1270, 920), "LHG Code Exercise");
    sf::Clock GameClock;

    // Grab textures and set up sprites
    sf::Texture PlayerTexture;
    sf::Texture AsteroidTexture;

    PlayerTexture.loadFromFile("Assets/Ship.png");
    AsteroidTexture.loadFromFile("Assets/Asteroid.png");

    sf::Sprite Player;
    Player.setTexture(PlayerTexture);
    sf::Sprite Asteroid;
    Asteroid.setTexture(AsteroidTexture);

    while (window.isOpen())
    {
        // Get the delta time for the game update
        sf::Time dt = GameClock.restart();

        // Poll for window being closed
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Reset the window
        window.clear();

        //-----------------------------------------------------------------------------------
        // Game logic can go here

        // Player ship follows the mouse
        sf::Vector2f MousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        Player.setPosition(MousePosition.x, MousePosition.y);
        window.draw(Player);

        // Asteroid spins in the center of the screen
        Asteroid.setPosition(400, 400);
        float Rotation = 90.0f;
        Asteroid.rotate(Rotation * dt.asSeconds());
        window.draw(Asteroid);

        //-----------------------------------------------------------------------------------
        // Display the updated game state
        window.display();
    }

    return 0;
}