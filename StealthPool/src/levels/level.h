#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "tiles\Tile.h"
#include "../entities/guard.h"

class Level
{
public:
	static const int tilenumber = 64 * 64;
	Level(sf::Shader &shader);
	~Level();

	void loadFromTilemap(std::string path);
	void draw(sf::RenderWindow &window, sf::Shader &shader);
	void update(const float &delta);
	std::vector<sf::IntRect> collisionTiles;
	std::vector<Guard> guards;
	std::vector<sf::IntRect> endTiles;
private:
	Tile tiles[64 * 64];

	sf::Texture walltexture;
	sf::Texture floortexture;
	sf::Texture nulltexture;
	sf::Texture dirttexture;
	sf::Texture endtexture;

	sf::Shader &shader;

};