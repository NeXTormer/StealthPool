#pragma once

#include "SFML\Graphics.hpp"

class Guard
{
public:
	Guard(sf::Vector2f pos);

	sf::Vector2f position;
	
	void draw(sf::RenderWindow &window);
	void update();
private:

	sf::Texture texture;
	sf::Sprite sprite;

};