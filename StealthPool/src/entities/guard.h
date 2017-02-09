#pragma once

#include <SFML\Graphics.hpp>

class Guard : public sf::Drawable, sf::Transformable
{
public:
	Guard(sf::Vector2f pos, sf::Texture &tileset);
	~Guard();

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void die();
	void update();

	sf::IntRect rect;
private:
	sf::Texture &tileset;
	sf::VertexArray mesh;
	bool dead;

};
