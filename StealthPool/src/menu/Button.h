#pragma once
#include <SFML\Graphics.hpp>
#include "../gamestates/menustate.h"


class Button : public sf::Drawable, public sf::Transformable
{
public:
	Button(sf::Vector2f pos, sf::Vector2i size, sf::Texture image, void (* callback) ());
	Button(sf::Vector2f pos, sf::Vector2i size, sf::Texture image, sf::Vector2f texturesize, void(* callback) ());

	void mousePressed(sf::Event e);
	void mouseMoved(sf::Event e);

	virtual void draw(sf::RenderTarget &target, sf::RenderStates renderstates) const;

	sf::Vector2i size;
	
private:
	
	sf::Texture image;
	sf::VertexArray mesh;
	sf::Vector2f texturesize;
	bool highlighted = false;

	void(*callback) ();
};