#pragma once
#include "Ball.h"
#include <SFML/Graphics.hpp>

class Player : public Ball {
public:
	Player(int x, int y);
	~Player();
	void update() override;
private:
	sf::Texture texture;

};