#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "tiles\Tile.h"
#include "../entities/guard.h"

class Level
{
public:
	static const int tilenumber = 64 * 64;
	Level();
	~Level();

	void loadFromTilemap(std::string path);
	void draw(sf::RenderWindow &window);
	void update(const float &delta);
	std::vector<sf::IntRect> collisionTiles;
	std::vector<Guard> guards;
private:
	Tile *tiles[64 * 64];

	sf::Texture walltexture;
	sf::Texture floortexture;
	sf::Texture nulltexture;

};