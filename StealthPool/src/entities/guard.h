#pragma once

#include <SFML\Graphics.hpp>

class Guard
{
public:
	Guard(sf::Vector2f pos);
	~Guard();

	void draw(sf::RenderWindow &window, sf::Shader &shader);
	void die();
	void update();

	sf::Vector2f position;

	sf::IntRect rect;
private:
	sf::Texture texture;
	sf::Texture deadTexture;
	sf::Sprite sprite;

	bool dead;


};
