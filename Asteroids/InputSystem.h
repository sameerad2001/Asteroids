#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "EventSystem.h"

class InputSystem {
public :
	static void UpdateInputSystem(sf::Event event);

protected:
	static std::unordered_map<sf::Keyboard::Key, bool> keysPressed;
};