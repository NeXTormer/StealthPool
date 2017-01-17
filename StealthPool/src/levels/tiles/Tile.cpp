#include "Tile.h"


Tile::Tile(sf::Texture &tex, int x, int y, bool collision)
{
	pos.x = x;
	pos.y = y;
	sprite.setTexture(tex);
	sprite.setPosition(x, y);
	collide = collision;
}

Tile::Tile(sf::Texture &tex, sf::Vector2f pos, bool collision)
{
	this->pos = pos;
	sprite.setTexture(tex);
	sprite.setPosition(pos);
	collide = collision;
}

Tile::Tile()
{
	render = false;
	collide = false;
}

void Tile::draw(sf::RenderWindow &window, sf::Shader &shader)
{
	window.draw(sprite, shader);
}
