#include "Tile.h"

Tile::Tile(sf::Texture &tex, int x, int y)
{
	pos.x = x;
	pos.y = y;
	sprite.setTexture(tex);
	sprite.setPosition(x, y);
}

Tile::Tile(sf::Texture &tex, sf::Vector2f pos)
{
	this->pos = pos;
	sprite.setTexture(tex);
	sprite.setPosition(pos);
}

void Tile::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}
