#pragma once

#include <SFML/Graphics.hpp>

#include "gamestate.h"
#include "../levels/level.h"

class PlayState : public GameState
{
public:
	PlayState(sf::RenderWindow &window, int lvlnr);
	~PlayState();

	void update(const float &delta) override;
	void draw() override;
	void mousePressed(sf::Event &ev);
	void mouseReleased(sf::Event &ev);


	Player *player;


private:
	const sf::Shader staticshader;

	Level level;
	sf::RenderWindow &window;

};