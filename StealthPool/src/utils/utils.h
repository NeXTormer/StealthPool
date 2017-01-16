#pragma once

#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 rng(rd());

int get_random_integer(int min, int max) 
{
	std::uniform_int_distribution<int> uni(min, max);
	return uni(rng);
}

float get_random_float(float min, float max)
{
	std::uniform_real_distribution<float> uni(min, max);
	return uni(rng);
}

sf::Vector2f convert_screenspace_to_worldspace(const sf::View &view, sf::Vector2i screenSpaceCoordinates)
{
	int diffx = view.getCenter().x - view.getSize().x * 0.5f;
	int diffy = view.getCenter().y - view.getSize().y * 0.5f;
	return sf::Vector2f(screenSpaceCoordinates.x + diffx, screenSpaceCoordinates.y + diffy);
}

