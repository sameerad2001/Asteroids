#include <iostream>
#include "InputSystem.h"

std::unordered_map<sf::Keyboard::Key, bool> InputSystem::keysPressed;

std::unordered_map<sf::Keyboard::Key, EventType> InputSystem::keyEvents = {
    {sf::Keyboard::Up,      THRUST},
    {sf::Keyboard::Down,    REVERSE},
    {sf::Keyboard::Right,   TURN_RIGHT},
    {sf::Keyboard::Left,    TURN_LEFT},
    {sf::Keyboard::Space,   FIRE},
    {sf::Keyboard::Enter,   GAME_START}
};

void InputSystem::ReceiveEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        keysPressed[event.key.code] = true;
    }
    else if (event.type == sf::Event::KeyReleased) {
        keysPressed[event.key.code] = false;
    }
}

void InputSystem::Update() {
    for (const auto& kvp : keysPressed) {
        if (kvp.second) {
            auto iter = keyEvents.find(kvp.first);
            if (iter != keyEvents.end()) {
                EventEmitter::EmitEvent(iter->second);
            }
        }
    }
}