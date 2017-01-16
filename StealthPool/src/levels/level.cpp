#include "level.h"
#include "SFML\Graphics.hpp"

Level::Level()
{
	walltexture.loadFromFile("res/wall.png");
	floortexture.loadFromFile("res/floor.png");
	nulltexture.loadFromFile("res/nulltexture.png");
}

Level::~Level()
{
	delete[] &tiles;
}

void Level::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < tilenumber; i++)
	{
		tiles[i]->draw(window);
	}
}

void Level::update(const float &delta)
{
	
}

std::vector<sf::IntRect>& Level::getCollisionTiles()
{
	return collisionTiles;
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
				tiles[y * 64 + x] = new Tile(walltexture, x * 32, y * 32, true);
			}
			else if (hcolor == 0x404040FF) {
				tiles[y * 64 + x] = new Tile(floortexture, x * 32, y * 32, false);
			}
			else if (hcolor == 0xFFFFFFFF) {
				tiles[y * 64 + x] = new Tile(); //create new voidtile (will not be rendered, not included in collision detection)
			}
			else {
				tiles[y * 64 + x] = new Tile(nulltexture, x * 32, y * 32, false);
			}

		}
	}

	for (unsigned int y = 0; y < 64; y++)
	{
		for (unsigned int x = 0; x < 64; x++)
		{
			if (tiles[y * 64 + x]->collide) 
			{
				collisionTiles.push_back(sf::IntRect(x * 32, y * 32, 32, 32));
			}
		}
	}
	


}



