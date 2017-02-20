#pragma once
#include <SFML/Graphics.hpp>

class GameState 
{
	friend class GameStateManager;
public:
	virtual bool update(const float &delta, sf::View &view) = 0;
	virtual void draw() = 0;
	virtual void handleEvent(sf::Event &e) = 0;

protected:
	bool active = false;
};