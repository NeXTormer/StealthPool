#include "guard.h"


Guard::Guard(sf::Vector2f pos)
{
	position = pos;
	texture.loadFromFile("res/guardtexture2.png");
}

void Guard::draw(sf::RenderWindow &window)
{
	sprite.setTexture(texture); //doesn't work in the constructor for some reason
	sprite.setPosition(position);
	window.draw(sprite);
}

void Guard::update()
{

}