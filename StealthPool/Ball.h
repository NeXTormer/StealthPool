#pragma once
#include "SFML\Graphics.hpp"

class Ball {

public:
	Ball(int x, int y);
	~Ball();
	virtual void setPos(int x, int y);
	virtual void update();
	virtual void draw(sf::RenderWindow &window);
	virtual void move(sf::Vector2f d);
	virtual void move(int dx, int dy);
private:
	sf::Vector2f *pos;
	float r;
	sf::CircleShape *shape;


};