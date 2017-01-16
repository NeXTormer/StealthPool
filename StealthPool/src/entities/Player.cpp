#include "player.h"
#include "../levels/level.h"

#include <math.h>

sf::Vector2f convert_screenspace_to_worldspace(const sf::View &view, sf::Vector2f screenSpaceCoordinates)
{
	int diffx = view.getCenter().x - view.getSize().x * 0.5f;
	int diffy = view.getCenter().y - view.getSize().y * 0.5f;
	return sf::Vector2f(screenSpaceCoordinates.x + diffx, screenSpaceCoordinates.y + diffy);
}


Player::Player(sf::RenderWindow &rwindow, Level &lvl, sf::Vector2f pos)
	: window(rwindow), position(pos), level(lvl)
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
	/* // redo friction
	if ((velocity.x < drag) && (velocity.x > -drag))
	{
		velocity.x = 0;
	}
	else 
	{
		if(velocity.x > 0) velocity.x -= drag;
		else velocity.x += drag;
	}
	if ((velocity.y < drag) && (velocity.y > -drag))
	{
		velocity.y = 0;
	}
	else
	{
		if (velocity.y > 0) velocity.y -= drag;
		else velocity.y += drag;
	}
	*/
	
	
	
	
	
	position += velocity;
}

void Player::draw()
{
	sf::Vector2f posw(position.x - radius, position.y - radius);
	sprite.setPosition(posw);
	window.draw(sprite);
}


void Player::mousePressed(sf::Event &ev) 
{
	sf::Vector2f mouseWorldSpace = convert_screenspace_to_worldspace(window.getView(), sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y));
	int diffx = std::abs(mouseWorldSpace.x - position.x);
	int diffy = std::abs(mouseWorldSpace.y - position.y);
	if ((diffx <= 16) && (diffy <= 16))
	{
		started = true;
		movement = true;
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
		velocity = start - end;
		velocity.x *= 0.02f;
		velocity.y *= 0.02f;
		started = false;
	}
}
