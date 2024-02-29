#include "InputSystem.h"

std::unordered_map<sf::Keyboard::Key, bool> InputSystem::keysPressed;

std::unordered_map<sf::Keyboard::Key, EventType> InputSystem::keyEvents = {
    {sf::Keyboard::Up,      THRUST},
    {sf::Keyboard::Down,    REVERSE},
    {sf::Keyboard::Right,   TURN_RIGHT},
    {sf::Keyboard::Left,    TURN_LEFT},
    {sf::Keyboard::Space,   FIRE}
};

void InputSystem::UpdateInputSystem(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        auto keyEvent = keyEvents.find(event.key.code);
        if (keyEvent == keyEvents.end()) return;

        keysPressed[event.key.code] = true;

        for (const auto& kvp : keysPressed) {
            if (kvp.second) {
                auto iter = keyEvents.find(kvp.first);
                if (iter != keyEvents.end()) {
                    EventEmitter::EmitEvent(iter->second);
                }
            }
        }
    }
    else if (event.type == sf::Event::KeyReleased) {
        auto iter = keysPressed.find(event.key.code);
        if (iter != keysPressed.end()) {
            iter->second = false;
        }
    }
}