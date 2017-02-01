#pragma once

#include <SFML\Graphics.hpp>

class Guard : public sf::Drawable, sf::Transformable
{
public:
	Guard(sf::Vector2f pos, sf::Shader &shader);
	~Guard();

	virtual void draw(sf::RenderTarget &rendertarget, sf::RenderStates renderstates) const;
	void die();
	void update();

	sf::IntRect rect;
private:
	sf::Texture texture;
	sf::Texture deadTexture;
	sf::VertexArray model;
	sf::Shader &shader;
	bool dead;


};
