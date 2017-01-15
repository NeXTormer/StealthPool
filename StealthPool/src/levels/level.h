#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "tiles\Tile.h"

class Level
{
public:
	static const int tilenumber = 64 * 64;
	Level();
	~Level();

	void loadFromTilemap(std::string path);
	void draw(sf::RenderWindow &window);
private:
	Tile *tiles[64 * 64];

	sf::Texture walltexture;
	sf::Texture floortexture;
	sf::Texture nulltexture;

};