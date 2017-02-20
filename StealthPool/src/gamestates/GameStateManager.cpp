#include "gamestatemanager.h"

GameStateManager::GameStateManager()
{
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::draw() 
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
	gamestate->active = true;
}

void GameStateManager::pop()
{
	gamestates.top()->active = false;
	gamestates.pop();
}

void GameStateManager::handleEvent(sf::Event &e)
{
	gamestates.top()->handleEvent(e);
}

