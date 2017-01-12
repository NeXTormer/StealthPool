#include "gamestatemanager.h"

GameStateManager::GameStateManager()
{
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::draw(sf::RenderWindow &window) 
{
	gamestates.top().draw(window);
}

void GameStateManager::update(const float &delta) 
{
	gamestates.top().update(delta);
}

void GameStateManager::push(const GameState &gamestate)
{
	gamestates.push(gamestate);
}

void GameStateManager::pop()
{
	gamestates.pop();
}

