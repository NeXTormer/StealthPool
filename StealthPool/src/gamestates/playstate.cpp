#include "playstate.h"

#include <iostream>
#include <string>
#include <stdlib.h>

sf::Vector2f convert_worldspace_to_screenspace(const sf::View &view, sf::Vector2f worldSpaceCoordinates)
{
	int diffx = view.getCenter().x - view.getSize().x * 0.5f;
	int diffy = view.getCenter().y - view.getSize().y * 0.5f;
	return sf::Vector2f(worldSpaceCoordinates.x - diffx, worldSpaceCoordinates.y - diffy);
}


PlayState::PlayState(sf::RenderWindow &rwindow, int lvlnr)
	: window(rwindow)
{

	staticshader = new sf::Shader();
	std::string pre = "res/levels/level";
	std::string nr = std::to_string(lvlnr);
	std::string suff = ".png";
	tilemap.loadFromFile(pre + nr + suff);
	player = new Player(rwindow, sf::Vector2f(300, 500), tilemap.collisionTiles, tilemap.guards);
	staticshader->loadFromFile("res/shader/staticshader.vert", "res/shader/staticshader.frag");
	tilemap.setShader(staticshader);

	levelnumber = lvlnr;
	if (levelnumber)
	{
		if (!credits.loadFromFile("res/credits.png"))
		{
			exit(EXIT_SUCCESS);
		}
		creditsSprite.setTexture(credits);
		creditsSprite.setPosition(sf::Vector2f(130, 580));
	}

}

void PlayState::mousePressed(sf::Event &ev)
{
	player->mousePressed(ev);
}

void PlayState::mouseReleased(sf::Event &ev)
{
	player->mouseReleased(ev);
}

PlayState::~PlayState()
{
	delete player;
}

bool PlayState::update(const float &delta, sf::View &view)
{
	player->update(delta, view);
	staticshader->setUniform("playerPosition", player->position);


	for (sf::IntRect rect : tilemap.endTiles)
	{
		if (rect.intersects(sf::IntRect(player->position.x - 16, player->position.y - 16, 32, 32)))
		{
			return true;
		}
	}
	return false;
}

void PlayState::draw()
{
	window.draw(tilemap);

	player->draw(staticshader);
	if (levelnumber == 1)
	{
		window.draw(creditsSprite);
	}
}
