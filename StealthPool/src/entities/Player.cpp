#include "player.h"


#include <math.h>
#include "../utils/utils.h"


Player::Player(sf::RenderWindow &rwindow, sf::Vector2f pos)
	: window(rwindow), position(pos)
{
	playertexture.loadFromFile("res/playertexture.png");
	sprite.setTexture(playertexture);
	start = pos;
	end = pos;
	drag = sf::Vector2f(1, 1);
}

Player::~Player() 
{
}

void Player::update(const float &delta)
{
	std::cout << convert_screenspace_to_worldspace(window.getView(), sf::Mouse::getPosition()).x << std::endl;

	handleInput();

	//implement drag

	//drag calculation
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
	if (firstClick)
	{
		start = position;
		end = position;
	}
	//std::cout << "mousepos: " << x << ", " << y << std::endl;
	//std::cout << "diff: " << x - position.x << ", " << y - position.y << std::endl;
		//std::cout << diffx << ", " << diffy << std::endl; //ball moves with this line, but not without it
	int x = ev.mouseButton.x;
	int y = ev.mouseButton.y;
	int diffx = std::abs(x - position.x);
	int diffy = std::abs(y - position.y);
	if((diffx <= 16) && (diffy <= 16))
	{
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
	if (firstClick)
	{
		start = position;
		end = position;
		//TODO: optimize
		int x = ev.mouseButton.x;
		int y = ev.mouseButton.y;
		int diffx = std::abs(x - position.x);
		int diffy = std::abs(y - position.y);
		if ((diffx <= 16) && (diffy <= 16))
		{
			firstClick = false;
		}
		else 
		{
			firstClick = false;
			return;
		}
	}
	if (started)
	{
		end.x = ev.mouseButton.x;
		end.y = ev.mouseButton.y;
		started = false;
	}
}