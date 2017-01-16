#pragma once
#include "gamestatemanager.h"

class MenuState : virtual public GameState
{
public:
	MenuState(sf::RenderWindow &window, GameStateManager &gamestatemanager);
	~MenuState();

	void update(const float &delta) override;
	void draw() override;

private:
	sf::Texture menuBackgroundTexture;
	sf::Sprite menuBackground;

	sf::Texture playBtnTexture;

	GameStateManager &gamestatemanager;
	sf::RenderWindow &window;
};