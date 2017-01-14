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
	sf::Color color;
	
	for (unsigned int y = 0; y < 64; y++) 
	{
		for (unsigned int x = 0; x < 64; x++)
		{
			color = tilemap.getPixel(x, y);
			if (color.toInteger() == 0x00000000) {

			}
		}
	}


}
