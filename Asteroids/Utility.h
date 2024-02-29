#pragma once
#include <SFML/Graphics.hpp>

sf::Vector2f Lerp(const sf::Vector2f& start, const sf::Vector2f& end, float t) {
	t = t < 0.0 ? 0.0 : t > 1.0 ? 1.0 : t;

	float lerpedX = start.x + t * (end.x - start.x);
	float lerpedY = start.y + t * (end.y - start.y);

	return sf::Vector2f(lerpedX, lerpedY);
}

sf::Vector2f RotateVector(const sf::Vector2f& vector, float angle) {
    float radianAngle = angle * (3.14f / 180.0f);
    float cosA = std::cos(radianAngle);
    float sinA = std::sin(radianAngle);

    return sf::Vector2f(vector.x * cosA - vector.y * sinA, vector.x * sinA + vector.y * cosA);
}

float VectorMagnitude(const sf::Vector2f& vector) {
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}