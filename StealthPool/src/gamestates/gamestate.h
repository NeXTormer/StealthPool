#pragma once
#include <SFML/Graphics.hpp>

class GameState 
{
public:
	virtual bool update(const float &delta, sf::View &view) = 0;
	virtual void draw() = 0;
};