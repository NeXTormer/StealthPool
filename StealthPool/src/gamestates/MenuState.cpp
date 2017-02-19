#include "menustate.h"
#include "gamestatemanager.h"

#include <SFML\Graphics.hpp>

sf::RectangleShape shape;

MenuState::MenuState(sf::RenderWindow &rwindow, GameStateManager &gsm)
	: gamestatemanager(gsm), window(rwindow)
{
	shape.setPosition(100, 100);
	//shape.setSize(sf::Vector2f(10, 400));
	menuBackgroundTexture.loadFromFile("res/menubackground.png");
}

MenuState::~MenuState()
{
}

void MenuState::draw()
{
	window.draw(shape);
}

bool MenuState::update(const float &delta, sf::View &view) 
{
	return false;

}
