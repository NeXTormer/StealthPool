#include "player.h"

Player::Player(sf::RenderWindow &window, sf::Vector2f pos)
	: window(window), pos(pos)
{
	playertexture.loadFromFile("res/playertexture.png");
	sprite.setTexture(playertexture);

}

Player::~Player() 
{
}

void Player::update(const float &delta)
{
	pos += velocity;

}

void Player::draw()
{
	sprite.setPosition(pos);
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
