#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "guard.h"


class Player 
{
public:
	sf::Vector2f position; //middle of the ball
	const int radius = 16;
	const int randiussquared = radius * radius;

	Player(sf::RenderWindow &window, sf::Vector2f pos, std::vector<sf::IntRect> &cTiles, std::vector<Guard> &gguards);
	~Player();

	void update(const float &delta, sf::View &view);
	void draw(sf::Shader &shader);

	void mousePressed(sf::Event &ev);
	void mouseReleased(sf::Event &ev);

private:

	sf::Texture playertexture;
	sf::Sprite sprite;
	sf::RenderWindow &window;
	sf::IntRect collisionbox;

	std::vector<sf::IntRect> &collisionTiles;
	std::vector<Guard> &guards;


	//vars for movement with mouse
	bool started = false; //true when mouse button is down
	bool movement = false;
	bool first = true;

	sf::Vector2f cartesianToPolar(const sf::Vector2f cartesian);
	sf::Vector2f polarToCartesian(const sf::Vector2f cartesian);

	float drag = 0.99;

	sf::Vector2f velocity;
	sf::Vector2f start;
	sf::Vector2f end;
};

