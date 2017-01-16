#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../levels/level.h"


class Player 
{
public:
	sf::Vector2f position; //middle of the ball
	const int radius = 16;
	const int randiussquared = radius * radius;

	Player(sf::RenderWindow &window, Level &level, sf::Vector2f pos);
	~Player();

	void update(const float &delta);
	void draw();

	void mousePressed(sf::Event &ev);
	void mouseReleased(sf::Event &ev);
private:

	Level &level;
	
	sf::Texture playertexture;
	sf::Sprite sprite;
	sf::RenderWindow &window;


	//vars for ballcontrol
	bool started = false; //true when mouse button is down
	bool movement = false;
	bool first = true;

	float drag = 10; //10 for 40 fps and no velocity reduction in mousereleased

	sf::Vector2f velocity;
	sf::Vector2f start;
	sf::Vector2f end;
};

