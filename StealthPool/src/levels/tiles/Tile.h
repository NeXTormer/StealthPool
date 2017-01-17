#pragma once

#include <SFML/Graphics.hpp>
#include "../../StealthPool/src/entities/player.h"

class Tile
{
public:
	Tile(sf::Texture &tex, int x, int y, bool collision);
	Tile(sf::Texture &tex, sf::Vector2f pos, bool collision);
	Tile();

	void draw(sf::RenderWindow &window);

	sf::Vector2f pos;
	int size = 32;
	bool render = false; //will not be rendered when false
	bool collide = false; //will not be included in collision detection when false
private:
	sf::Sprite sprite;

};