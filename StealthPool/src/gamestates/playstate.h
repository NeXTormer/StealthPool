#pragma once

#include <SFML/Graphics.hpp>

#include "gamestate.h"
#include "../entities/player.h"
#include "../levels/tiles/tilemap.h"

class PlayState : public GameState
{
public:
	PlayState(sf::RenderWindow &window, int lvlnr);
	~PlayState();

	bool update(const float &delta, sf::View &view) override;
	void draw() override;
	void handleEvent(sf::Event &e) override;
	void mousePressed(sf::Event &ev);
	void mouseReleased(sf::Event &ev);
	bool isActive();
	Player *player;

	static sf::Shader *shader;
private:
	int levelnumber;
	TileMap tilemap;
	sf::RenderWindow &window;
	sf::Texture credits;
	sf::Sprite creditsSprite;

};