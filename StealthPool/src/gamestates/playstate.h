#pragma once

#include <SFML/Graphics.hpp>

#include "gamestate.h"
#include "../levels/level.h"
#include "../entities/player.h"

class PlayState : public GameState
{
public:
	PlayState(sf::RenderWindow &window, int lvlnr);
	~PlayState();

	bool update(const float &delta, sf::View &view) override;
	void draw() override;
	void mousePressed(sf::Event &ev);
	void mouseReleased(sf::Event &ev);


	Player *player;


private:
	sf::Shader staticshader;

	Level level;
	sf::RenderWindow &window;

};