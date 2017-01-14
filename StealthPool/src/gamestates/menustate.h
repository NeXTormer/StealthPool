#pragma once
#include "gamestatemanager.h"

class MenuState : virtual public GameState
{
public:
	MenuState(GameStateManager &gamestatemanager);
	~MenuState();

	void update(const float &delta) override;
	void draw(sf::RenderWindow &window) override;

private:
	sf::Texture menuBackgroundTexture;
	sf::Sprite menuBackground;

	sf::Texture playBtnTexture;

	GameStateManager &gamestatemanager;
};