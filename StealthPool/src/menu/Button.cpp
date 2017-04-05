#include "Button.h"

Button::Button(sf::Vector2f pos, sf::Vector2i size, sf::Texture image, sf::Vector2f texturesize, void(* callbackf) ())
	: mesh(sf::Quads, 4)
{
	this->callback = callbackf;
	setPosition(pos);
	this->size = size;
	this->texturesize = texturesize;
}

Button::Button(sf::Vector2f pos, sf::Vector2i size, sf::Texture image, void(* callbackf) ())
	: mesh(sf::Quads, 4)
{
	this->callback = callbackf;
	setPosition(pos);
	this->size = size;
	texturesize = sf::Vector2f(size);
}

void Button::mousePressed(sf::Event e)
{
	if (sf::IntRect(sf::Vector2i(getPosition().x, getPosition().y), size).contains(e.mouseButton.x, e.mouseButton.y))
	{
		callback;
	}
}

void Button::mouseMoved(sf::Event e)
{
	if (sf::IntRect(sf::Vector2i(getPosition().x, getPosition().y), size).contains(e.mouseButton.x, e.mouseButton.y))
	{
		if (!highlighted)
		{
			highlighted = true;
			mesh[0].texCoords = sf::Vector2f(texturesize.x, 0);
			mesh[1].texCoords = sf::Vector2f(texturesize.x * 2, 0);
			mesh[2].texCoords = sf::Vector2f(texturesize.x * 2, texturesize.y);
			mesh[3].texCoords = sf::Vector2f(texturesize.x, texturesize.y);
		}
	}
	else
	{
		if (highlighted)
		{
			highlighted = false;
			mesh[0].texCoords = sf::Vector2f(0, 0);
			mesh[1].texCoords = sf::Vector2f(texturesize.x, 0);
			mesh[2].texCoords = sf::Vector2f(texturesize.x, texturesize.y);
			mesh[3].texCoords = sf::Vector2f(0, texturesize.y);
		}
	}
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates renderstates) const
{
	renderstates.transform = getTransform();
	renderstates.texture = &image;
	
	target.draw(mesh, renderstates);

}

