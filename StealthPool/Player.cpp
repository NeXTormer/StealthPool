#include "Player.h"


Player::Player(int x, int y)
	: Ball::Ball(x, y)
{

}

Player::~Player()
{
	Ball::~Ball();
}

void Player::update()
{
	//Ball::setPos(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
	
	Ball::update();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) Ball::move(-5, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) Ball::move(0, -5);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) Ball::move(0, 5);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) Ball::move(5, 0);
}
