#include "guard.h"
#include <iostream>
#include "../gamestates/playstate.h"

Guard::~Guard()
{

}

Guard::Guard(sf::Vector2f pos, sf::Texture &texture)
	: rect(sf::Vector2i(pos.x, pos.y), sf::Vector2i(32, 32)), mesh(sf::Quads, 4), tileset(texture)
{

	setPosition(pos);
	tileset.loadFromFile("res/tileset.png");
	dead = false;

	mesh[0] = sf::Vector2f(0, 0);
	mesh[1] = sf::Vector2f(32, 0);
	mesh[2] = sf::Vector2f(32, 32);
	mesh[3] = sf::Vector2f(0, 32);

	mesh[0].texCoords = sf::Vector2f(0, 32);
	mesh[1].texCoords = sf::Vector2f(32, 32);
	mesh[2].texCoords = sf::Vector2f(32, 64);
	mesh[3].texCoords = sf::Vector2f(0, 64);

}


void Guard::draw(sf::RenderTarget &rendertarget, sf::RenderStates renderstates) const
{

	renderstates.transform = getTransform();
	renderstates.shader = PlayState::shader;
	renderstates.texture = &tileset;
	
	rendertarget.draw(mesh, renderstates);
}

void Guard::die()
{
	dead = true;
	mesh[0].texCoords = sf::Vector2f(32, 32);
	mesh[1].texCoords = sf::Vector2f(64, 32);
	mesh[2].texCoords = sf::Vector2f(64, 64);
	mesh[3].texCoords = sf::Vector2f(32, 64);
}

void Guard::update()
{

}