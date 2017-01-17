#include "guard.h"

Guard::~Guard()
{

}

Guard::Guard(sf::Vector2f pos)
	: rect(sf::Vector2i(pos.x, pos.y), sf::Vector2i(32, 32))
{
	position = pos;
	texture.loadFromFile("res/guardtexture2.png");
	deadTexture.loadFromFile("res/guardtextureDead.png");
	dead = false;
}

void Guard::draw(sf::RenderWindow &window, sf::Shader &shader)
{
	if (dead)
	{
		sprite.setTexture(deadTexture); //doesn't work in the constructor for some reason
	} 
	else
	{
		sprite.setTexture(texture); //doesn't work in the constructor for some reason
	}

	sprite.setPosition(position);
	window.draw(sprite, &shader);
}

void Guard::die()
{
	dead = true;
}

void Guard::update()
{

}