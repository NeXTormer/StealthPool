#include "player.h"

#include <math.h>

Player::Player(sf::RenderWindow &rwindow, sf::Vector2f pos)
	: window(rwindow), position(pos)
{
	playertexture.loadFromFile("res/playertexture.png");
	sprite.setTexture(playertexture);
	start = pos;
	end = pos;
}

Player::~Player() 
{
}

void Player::update(const float &delta)
{
	handleInput();
	position += velocity;
	//std::cout << "ballpos: " << position.x << ", " << position.y << std::endl;

}

void Player::draw()
{
	sf::Vector2f posw(position.x - radius, position.y - radius);
	sprite.setPosition(posw);
	window.draw(sprite);
}


//TODO: convert mouse pos into world cordinates
void Player::handleInput()
{
	if (!started)
	{
		velocity = start - end;
		velocity *= 0.02f;
	}
}

void Player::mousePressed(sf::Event &ev) 
{
	int x = ev.mouseButton.x;
	int y = ev.mouseButton.y;
	//std::cout << "mousepos: " << x << ", " << y << std::endl;
	//std::cout << "diff: " << x - position.x << ", " << y - position.y << std::endl;
	int diffx = std::abs(x - position.x);
	int diffy = std::abs(y - position.y);
	if((diffx <= 16) && (diffy <= 16))
	{
		//std::cout << diffx << ", " << diffy << std::endl; //ball moves with this line, but not without it
		started = true;
		pressedOutOfBounds = false;
		start.x = x;
		start.y = y;
	}
	else
	{
		pressedOutOfBounds = true;
	}
}

void Player::mouseReleased(sf::Event &ev)
{
	if (started)
	{
		end.x = ev.mouseButton.x;
		end.y = ev.mouseButton.y;
		started = false;
	}
}
