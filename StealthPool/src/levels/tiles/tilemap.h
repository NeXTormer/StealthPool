#pragma once

#include <SFML/Graphics.hpp>
#include "../../entities/guard.h"

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void loadFromFile(sf::String path);
	std::vector<Guard> guards;
	std::vector<sf::IntRect> collisionTiles;
	std::vector<sf::IntRect> endTiles;
private:
	sf::Texture tileset;
	sf::VertexArray mesh; //static?
	int width = 64;
	int height = 64;
	int tilesize = 32;	
};