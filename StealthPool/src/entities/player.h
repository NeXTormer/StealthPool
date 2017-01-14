#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player 
{
public:
	sf::Vector2f pos;
	
	Player(sf::RenderWindow &window, sf::Vector2f pos);
	Player(sf::RenderWindow &window);
	~Player();

	void update(const float &delta);
	void draw();
private:
	sf::CircleShape m_shape;
	sf::Texture m_texture;
	sf::RenderWindow &m_window;
};

