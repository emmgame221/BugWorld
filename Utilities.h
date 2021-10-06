#pragma once
#include <SFML/Graphics.hpp>

#define PI 3.14159f

double angle(sf::Vector2f a, sf::Vector2f b) {
	return (atan2((b.y - a.y), (b.x - a.x)) * 180 / PI);
}

sf::Vector2f normalize(sf::Vector2f vec) {
	float mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	return sf::Vector2f(vec.x / mag, vec.y / mag);
}

double distance(sf::Vector2f a, sf::Vector2f b) {
	return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}