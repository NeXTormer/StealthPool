#pragma once
#include <SFML/Graphics.hpp>

class GameState 
{
public:
	virtual void update(const float &delta) = 0;
	virtual void draw() = 0;

private:

	
};