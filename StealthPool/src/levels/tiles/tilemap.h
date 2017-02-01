#pragma once

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void loadFromFile(sf::String path);
	void setShader(sf::Shader *shader);
private:
	sf::Shader *shader;
	sf::Texture tileset;
	void loadTileSet(sf::String path);
	
	
};