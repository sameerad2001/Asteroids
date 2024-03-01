#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "EventSystem.h"

class InputSystem {
public :
	static void ReceiveEvent(sf::Event event);
	static void Update();

protected:
	static std::unordered_map<sf::Keyboard::Key, EventType> keyEvents;
	static std::unordered_map<sf::Keyboard::Key, bool> keysPressed;
};