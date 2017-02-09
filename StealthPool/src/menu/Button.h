#pragma once
#include <SFML\Graphics.hpp>


class Button// : public sf::Drawable, public sf::Transformable
{
public:
	Button();
	Button(sf::Vector2f pos, sf::Vector2f size, sf::Texture image, void (*callback) ());

	void mousePressed(sf::Event e);

private:
	void(*callback) ();


};