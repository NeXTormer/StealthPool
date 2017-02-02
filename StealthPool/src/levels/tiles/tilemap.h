#pragma once

#include <SFML/Graphics.hpp>
#include "../../entities/guard.h"

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void loadFromFile(sf::String path);
	void setShader(sf::Shader *shader);
	std::vector<Guard> guards;
	std::vector<sf::IntRect> collisionTiles;
	std::vector<sf::IntRect> endTiles;
private:
	sf::Shader *shader;
	sf::Texture tileset;
	static sf::VertexArray mesh;
	int width = 64;
	int height = 64;
	int tilesize = 32;	
};