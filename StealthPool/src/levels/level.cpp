#include "level.h"

Level::Level()
{
	walltexture.loadFromFile("res/wall.png");
	floortexture.loadFromFile("res/floor.png");
	nulltexture.loadFromFile("res/nulltexture.png");
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
			unsigned int hcolor = color.toInteger();
			if (hcolor == 0x00FFFFFF) {
				tiles[y * 64 + x] = new Tile(walltexture, x * 32, y * 32);
			}
			else if (hcolor == 0x404040FF) {
				tiles[y * 64 + x] = new Tile(floortexture, x * 32, y * 32);
			}
			else {
				tiles[y * 64 + x] = new Tile(nulltexture, x * 32, y * 32);
			}

		}
	}


}

void Level::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < tilenumber; i++)
	{
		tiles[i]->draw(window);
	}
}
