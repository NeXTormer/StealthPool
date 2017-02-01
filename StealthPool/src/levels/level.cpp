#include "level.h"
#include "SFML\Graphics.hpp"

Level::Level(sf::Shader &shader)
	: shader(shader)
{
	walltexture.loadFromFile("res/wall.png");
	floortexture.loadFromFile("res/floor.png");
	nulltexture.loadFromFile("res/nulltexture.png");
	dirttexture.loadFromFile("res/dirttexture.png");
	endtexture.loadFromFile("res/endtexture.png");
}

Level::~Level()
{

}

void Level::draw(sf::RenderWindow& window, sf::Shader &shader)
{
	for (int i = 0; i < tilenumber; i++)
	{
		tiles[i].draw(window, shader);
	}
	for (int i = 0; i < guards.size(); i++)
	{
		window.draw(guards[i]);
	}
}

void Level::update(const float &delta)
{
	for (int i = 0; i < guards.size(); i++)
	{
		guards[i].update();
	}
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
				tiles[y * 64 + x] = Tile(walltexture, x * 32, y * 32, true);
				collisionTiles.push_back(sf::IntRect(x * 32, y * 32, 32, 32)); //add tile to  collisionTiles to make it collideable
			}
			else if (hcolor == 0x404040FF) {
				tiles[y * 64 + x] = Tile(floortexture, x * 32, y * 32, false);
			}
			else if (hcolor == 0x4CFF00FF) {
				guards.push_back(Guard(sf::Vector2f(x * 32, y * 32), shader)); //add a new guard to the vector
				tiles[y * 64 + x] = Tile();	//create a voidtile 'under' the guard
			}
			else if (hcolor == 0xFFFFFFFF) {
				tiles[y * 64 + x] = Tile();
			}
			else if (hcolor == 0xFF00FFFF) {
				tiles[y * 64 + x] = Tile(endtexture, x * 32, y * 32, false);
				endTiles.push_back(sf::IntRect(x * 32, y * 32, 32, 32));
			}
			else if (hcolor == 0xFFFF00FF) {
				tiles[y * 64 + x] = Tile(dirttexture, x * 32, y * 32, false);
			}
			else {
				tiles[y * 64 + x] = Tile(nulltexture, x * 32, y * 32, false);
			}

		}
	}
}



