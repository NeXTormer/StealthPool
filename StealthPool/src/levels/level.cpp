#include "level.h"

Level::Level()
{
}

Level::~Level()
{
	delete[] tiles;
}

void Level::loadFromTilemap(std::string path)
{
	sf::Image tilemap;
	tilemap.loadFromFile(path);
	
}
