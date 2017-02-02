#include "guard.h"

Guard::~Guard()
{

}

Guard::Guard(sf::Vector2f pos, sf::Shader &shader)
	: rect(sf::Vector2i(pos.x, pos.y), sf::Vector2i(32, 32)), model(sf::Quads, 4), shader(shader)
{
	setPosition(pos);
	texture.loadFromFile("res/guardtexture2.png");
	deadTexture.loadFromFile("res/guardtextureDead.png");
	dead = false;

	model[0] = sf::Vector2f(0, 0);
	model[1] = sf::Vector2f(32, 0);
	model[2] = sf::Vector2f(32, 32);
	model[3] = sf::Vector2f(0, 32);

	model[0].texCoords = sf::Vector2f(0, 0);
	model[1].texCoords = sf::Vector2f(32, 0);
	model[2].texCoords = sf::Vector2f(32, 32);
	model[3].texCoords = sf::Vector2f(0, 32);
}

void Guard::draw(sf::RenderTarget &rendertarget, sf::RenderStates renderstates) const
{

	renderstates.transform = getTransform();
	renderstates.shader = &shader;
	
	if (dead)
	{
		renderstates.texture = &deadTexture;
	} 
	else
	{
		renderstates.texture = &texture;
	}

	rendertarget.draw(model, renderstates);
}

void Guard::die()
{
	dead = true;
}

void Guard::update()
{

}