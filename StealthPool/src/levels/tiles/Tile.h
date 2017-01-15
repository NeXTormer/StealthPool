#pragma once

#include <SFML/Graphics.hpp>

class Tile
{
public:
	Tile(sf::Texture &tex, int x, int y);
	Tile(sf::Texture &tex, sf::Vector2f pos);

	void draw(sf::RenderWindow &window);

	sf::Vector2f pos;
	int size = 32;
private:
	sf::Sprite sprite;

private:
	static sf::Texture wallTexture;
	static sf::Texture floorTexture;
};