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

void GameStateManager::update(const float &delta, sf::View &view) 
{
	gamestates.top()->update(delta, view);
}

void GameStateManager::push(GameState *gamestate)
{
	gamestates.push(gamestate);
}

void GameStateManager::pop()
{
	gamestates.pop();
}

