#pragma once
#include <SFML/Graphics.hpp>

constexpr float PI = 3.14159f;

float angle(sf::Vector2f a, sf::Vector2f b) {
	return (atan2((b.y - a.y), (b.x - a.x)) * 180 / PI);
}

sf::Vector2f normalize(sf::Vector2f vec) {
	float mag = sqrt(powf(vec.x, 2) + powf(vec.y, 2));
	return sf::Vector2f(vec.x / mag, vec.y / mag);
}

float distance(sf::Vector2f a, sf::Vector2f b) {
	return sqrt(powf((b.x - a.x), 2) + powf((b.y - a.y), 2));
}