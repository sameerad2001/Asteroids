#include "InputSystem.h"

void InputSystem::UpdateInputSystem(sf::Event event) {
    if (event.type == sf::Event::KeyPressed)
        keysPressed[event.key.code] = true;
    else if (event.type == sf::Event::KeyReleased)
        keysPressed[event.key.code] = false;
    else
        return;

    if (keysPressed[sf::Keyboard::Up])
        EventEmitter::EmitEvent(THRUST);
    if (keysPressed[sf::Keyboard::Down])
        EventEmitter::EmitEvent(REVERSE);
    if (keysPressed[sf::Keyboard::Right])
        EventEmitter::EmitEvent(TURN_RIGHT);
    if (keysPressed[sf::Keyboard::Left])
        EventEmitter::EmitEvent(TURN_LEFT);
}

std::unordered_map<sf::Keyboard::Key, bool> InputSystem::keysPressed;
