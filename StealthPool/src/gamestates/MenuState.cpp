#include "menustate.h"
#include "gamestatemanager.h"

#include <SFML\Graphics.hpp>

sf::RectangleShape shape;

MenuState::MenuState(GameStateManager &gsm)
{
	shape.setPosition(100, 100);
	shape.setSize(sf::Vector2f(10, 400));
	menuBackgroundTexture.loadFromFile("res/menubackground.png");
}

MenuState::~MenuState()
{
}

void MenuState::draw(sf::RenderWindow &window)
{
	window.draw(shape);
}

void MenuState::update(const float &delta) 
{


}
