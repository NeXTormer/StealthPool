#include "Button.h"

Button::Button()
{

}

Button::Button(sf::Vector2f pos, sf::Vector2f size, sf::Texture image, void(*callbackf) ())
{
	this->callback = callbackf;
}

void Button::mousePressed(sf::Event e)
{

}
