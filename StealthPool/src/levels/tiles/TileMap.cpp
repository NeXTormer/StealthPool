#include "tilemap.h"

TileMap::TileMap()
{

}

void TileMap::loadFromFile(sf::String path)
{

}

void TileMap::setShader(sf::Shader *shader)
{
	this->shader = shader;
}

void TileMap::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

}

void TileMap::loadTileSet(sf::String path)
{
	tileset.loadFromFile(path);
}
