#pragma once

#include "SFML\Graphics.hpp"

class Guard
{
public:
	Guard(sf::Vector2f pos);
	~Guard();

	sf::Vector2f position;
	
	void draw(sf::RenderWindow &window);
	void update();
	void die();

	sf::IntRect rect;
private:

	bool dead;

	sf::Texture texture;
	sf::Texture deadTexture;
	sf::Sprite sprite;

};