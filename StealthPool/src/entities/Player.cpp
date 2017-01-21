#include "player.h"
#include "../levels/level.h"

#include <math.h>

#define LOG(x) std::cout << x << std::endl

sf::Vector2f convert_screenspace_to_worldspace(const sf::View &view, sf::Vector2f screenSpaceCoordinates)
{
	int diffx = view.getCenter().x - view.getSize().x * 0.5f;
	int diffy = view.getCenter().y - view.getSize().y * 0.5f;
	return sf::Vector2f(screenSpaceCoordinates.x + diffx, screenSpaceCoordinates.y + diffy);
}


Player::Player(sf::RenderWindow &rwindow, sf::Vector2f pos, std::vector<sf::IntRect> &cTiles, std::vector<Guard> &gguards)
	: window(rwindow), position(pos), collisionTiles(cTiles), guards(gguards)
{
	playertexture.loadFromFile("res/playertexture.png");
	sprite.setTexture(playertexture);
	start = pos;
	end = pos;
}

Player::~Player() 
{
}

//rect.left = x
//rect.top = y

void Player::update(const float &delta, sf::View &view)
{  
	sf::Vector2f ppos = position;
	
	//calculate drag

	velocity.x *= drag;
	velocity.y *= drag;
	


	position += velocity;
	//collision
	sf::Vector2i ballPos(position.x - radius, position.y - radius);
	sf::Vector2i ballSize(32, 32);
	for (sf::IntRect r : collisionTiles)
	{
		
		if (r.intersects(sf::IntRect(ballPos, ballSize)))
		{
			float tilex = r.left + 16;
			float tiley = r.top + 16;
			float dx = std::abs(position.x - (tilex));
			float dy = std::abs(position.y - (tiley));

			float absvelx = std::abs(velocity.x);
			float absvely = std::abs(velocity.y);

			if (dx >= dy)
			{
				if (position.x > tilex)
				{
					//LOG("left");
					velocity.x = absvelx;
					//velocity.y = 0;
					position = ppos;

				}
				else if (position.x < tilex)
				{
					//LOG("right");
					velocity.x = -absvelx;
					//velocity.y = 0;
					position = ppos;
				}
			} 
			else if (dy > dx)
			{
				if (position.y > tiley)
				{
					//LOG("top");
					//velocity.x = 0;
					velocity.y = absvely;
					position = ppos;
				}
				else if (position.y < tiley)
				{
					//LOG("Bottom");
					//velocity.x = 0;
					velocity.y = -absvely;
					position = ppos;
				}

			}
			position = ppos;
			position += velocity;
			
		}
		view.setCenter(position);

	}

	//collision with guard
	for (int i = 0; i < guards.size(); i++)
	{
		if (guards[i].rect.intersects(sf::IntRect(ballPos, ballSize)))
		{
			guards[i].die();
		}
	}

}

void Player::draw(sf::Shader &shader)
{
	sf::Vector2f posw(position.x - radius, position.y - radius);
	sprite.setPosition(posw);
	window.draw(sprite, &shader);
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

sf::Vector2f Player::cartesianToPolar(const sf::Vector2f cartesian)
{
	return sf::Vector2f(std::sqrt(cartesian.x * cartesian.x + cartesian.y * cartesian.y), std::atan(cartesian.y / cartesian.x));
}

sf::Vector2f Player::polarToCartesian(const sf::Vector2f polar)
{
	return sf::Vector2f(polar.x * std::cos(polar.y), polar.x * std::sin(polar.y));
}