#pragma once

#include <SFML/Graphics.hpp>

#include "gamestate.h"
#include "../levels/level.h"

class PlayState : public GameState
{
public:
	PlayState(int lvlnr);
	~PlayState();

	void update(const float &delta) override;
	void draw(sf::RenderWindow &window) override;

private:
	Level level;

};