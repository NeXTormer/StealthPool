#include "gamestatemanager.h"

GameStateManager::GameStateManager()
{
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::draw(sf::RenderWindow &window) 
{
	gamestates.top()->draw();
}

void GameStateManager::update(const float &delta) 
{
	gamestates.top()->update(delta);
}

void GameStateManager::push(GameState *gamestate)
{
	gamestates.push(gamestate);
}

void GameStateManager::pop()
{
	gamestates.pop();
}

