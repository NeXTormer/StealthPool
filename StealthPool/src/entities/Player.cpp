#include "player.h"


#include <math.h>

sf::Vector2f convert_screenspace_to_worldspace(const sf::View &view, sf::Vector2f screenSpaceCoordinates)
{
	int diffx = view.getCenter().x - view.getSize().x * 0.5f;
	int diffy = view.getCenter().y - view.getSize().y * 0.5f;
	return sf::Vector2f(screenSpaceCoordinates.x + diffx, screenSpaceCoordinates.y + diffy);
}


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
		velocity.x *= 0.02f;
		velocity.y *= 0.02f;
	}
}

void Player::mousePressed(sf::Event &ev) 
{
	sf::Vector2f mouseWorldSpace = convert_screenspace_to_worldspace(window.getView(), sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y));
	int diffx = std::abs(mouseWorldSpace.x - position.x);
	int diffy = std::abs(mouseWorldSpace.y - position.y);
	if ((diffx <= 16) && (diffy <= 16))
	{
		started = true;
		start.x = ev.mouseButton.x;
		start.y = ev.mouseButton.y;

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