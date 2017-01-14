#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "tiles\Tile.h"

class Level
{
public:
	Level();
	~Level();

	void loadFromTilemap(std::string path);
private:
	Tile *tiles[64 * 64];
};