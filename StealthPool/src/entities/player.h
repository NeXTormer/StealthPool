#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class Player 
{
public:
	sf::Vector2f position; //middle of the ball
	const int radius = 16;
	const int randiussquared = radius * radius;

	Player(sf::RenderWindow &window, sf::Vector2f pos);
	~Player();

	void update(const float &delta);
	void draw();

	void mousePressed(sf::Event &ev);
	void mouseReleased(sf::Event &ev);

private:
	void handleInput();

	sf::Texture playertexture;
	sf::Sprite sprite;
	sf::RenderWindow &window;


	//vars for ballcontrol
	bool started = false; //true when mouse button is down


	sf::Vector2f velocity;
	sf::Vector2f start;
	sf::Vector2f end;
	sf::Vector2f drag;
};

