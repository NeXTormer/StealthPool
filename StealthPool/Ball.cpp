#include "Ball.h"
#include <SFML\Graphics.hpp>


Ball::Ball(int x, int y) {
	this->pos = new sf::Vector2f(x, y);
	this->r = 30;

	shape = new sf::CircleShape(r);
}



Ball::~Ball() {
	delete shape;
}

void Ball::setPos(int x, int y)
{
	this->pos = new sf::Vector2f(x, y);
}

void Ball::update() {
	shape->setPosition(*pos);
}

void Ball::draw(sf::RenderWindow &window) {
	window.draw(*shape);
}

void Ball::move(sf::Vector2f d)
{
	this->pos->x += d.x;
	this->pos->y += d.y;
}

void Ball::move(int dx, int dy)
{
	this->pos->x += dx;
	this->pos->y += dy;
}

