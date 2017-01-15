#include "player.h"

Player::Player(sf::RenderWindow &rwindow, sf::Vector2f pos)
	: window(rwindow), position(pos)
{
	playertexture.loadFromFile("res/playertexture.png");
	sprite.setTexture(playertexture);

}

Player::~Player() 
{
}

void Player::update(const float &delta)
{
	position += velocity;

}

void Player::draw()
{
	sprite.setPosition(position);
	window.draw(sprite);
}

void Player::handleInput()
{
	if (window.hasFocus()) 
	{
		if (!started)
		{
			velocity = start - end;
			velocity *= 0.07f;
		}
	}
}

void Player::mousePressed(sf::Event &ev) 
{
	started = true;
	start.x = ev.mouseButton.x;
	start.y = ev.mouseButton.y;
}

void Player::mouseReleased(sf::Event &ev)
{
	if (started)
	{
		end.x = ev.mouseButton.x;
		end.y = ev.mouseButton.y;
	}
}
