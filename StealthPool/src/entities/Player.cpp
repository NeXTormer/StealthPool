#include "player.h"

Player::Player(sf::RenderWindow &window, sf::Vector2f pos)
	: m_window(window)
{
	this->pos = pos;
}

Player::Player(sf::RenderWindow &window)
	: m_window(window)
{
	this->pos = sf::Vector2f(100, 100);
}

Player::~Player() 
{
}

void Player::update(const float & delta)
{
}

void Player::draw()
{
}
