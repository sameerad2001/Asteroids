#pragma once
#include <SFML/Graphics.hpp>

sf::Vector2f Lerp(const sf::Vector2f& start, const sf::Vector2f& end, float t) {
	t = t < 0.0 ? 0.0 : t > 1.0 ? 1.0 : t;

	float lerpedX = start.x + t * (end.x - start.x);
	float lerpedY = start.y + t * (end.y - start.y);

	return sf::Vector2f(lerpedX, lerpedY);
}