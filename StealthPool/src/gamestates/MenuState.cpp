#include "menustate.h"
#include "gamestatemanager.h"

#include <SFML\Graphics.hpp>

sf::RectangleShape shape;

MenuState::MenuState(sf::RenderWindow &rwindow, GameStateManager &gsm)
	: gamestatemanager(gsm), window(rwindow), playbutton(sf::Vector2f(300, 300), sf::Vector2i(178, 92), playBtnTexture, buttonPressed)
{
	menuBackgroundTexture.loadFromFile("res/menubackground.jpg");
	menuBackground.setTexture(menuBackgroundTexture);
	menuBackground.setPosition(-300, 200);
}

MenuState::~MenuState()
{
}

void MenuState::draw()
{
	window.draw(menuBackground);
	window.draw(playbutton);
}

bool MenuState::update(const float &delta, sf::View &view) 
{
	return false;
}

void MenuState::handleEvent(sf::Event &e)
{
}

void MenuState::buttonPressed()
{

}
