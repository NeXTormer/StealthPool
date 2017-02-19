#pragma once

#include <stack>
#include <SFML/Graphics.hpp>

#include "gamestate.h"

class GameStateManager
{
public:
	GameStateManager();
	~GameStateManager();
	void draw();
	void update(const float &delta, sf::View &view);
	void push(GameState *gamestate);
	void pop();
private:
	std::stack<GameState*> gamestates;
};
