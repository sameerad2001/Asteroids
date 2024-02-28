#pragma once
#include <SFML/Graphics.hpp>
#include "EventSystem.h"

class InputSystem {
public :
	static void UpdateInputSystem(sf::Event event) {
		if (event.type == sf::Event::KeyPressed && event.key.scancode == sf::Keyboard::Scan::Up)
			EventEmitter::EmitEvent(THRUST);
	}

protected:
};