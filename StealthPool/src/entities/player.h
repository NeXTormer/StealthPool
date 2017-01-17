#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class Player 
{
public:
	sf::Vector2f position; //middle of the ball
	const int radius = 16;
	const int randiussquared = radius * radius;

	Player(sf::RenderWindow &window, sf::Vector2f pos, std::vector<sf::IntRect> &cTiles);
	~Player();

	void update(const float &delta);
	void draw();

	void mousePressed(sf::Event &ev);
	void mouseReleased(sf::Event &ev);
	//TODO: implement collision response methods (ie. void collision(direction))

private:

	sf::Texture playertexture;
	sf::Sprite sprite;
	sf::RenderWindow &window;
	sf::IntRect collisionbox;

	std::vector<sf::IntRect> &collisionTiles;


	//vars for ballcontrol
	bool started = false; //true when mouse button is down
	bool movement = false;
	bool first = true;

	float drag = 10; //10 for 40 fps and no velocity reduction in mousereleased

	sf::Vector2f velocity;
	sf::Vector2f start;
	sf::Vector2f end;
};

