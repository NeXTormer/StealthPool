#pragma once
#include "gamestatemanager.h"
#include "../menu/Button.h"


class MenuState : virtual public GameState
{
public:
	MenuState(sf::RenderWindow &window, GameStateManager &gamestatemanager);
	~MenuState();

	bool update(const float &delta, sf::View &view) override;
	void draw() override;
	void handleEvent(sf::Event &e) override;
private:
	void buttonPressed();

	sf::Texture menuBackgroundTexture;
	sf::Sprite menuBackground;

	sf::Texture playBtnTexture;

	GameStateManager &gamestatemanager;
	sf::RenderWindow &window;
};