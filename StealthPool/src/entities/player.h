#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player 
{
public:
	sf::Vector2f pos;
	
	void update(const float &delta);
	void draw(sf::RenderWindow &window);
private:
	sf::CircleShape shape;
	sf::Texture texture;
};

