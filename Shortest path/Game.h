#pragma once

#include "Grid.h"

class Game
{
public:
	Game(std::pair<int, int> start, std::pair<int, int> finish);
	~Game();
	void run();
private:
	void update();
	void updatePollEvents();
	void render();

	void initVariables(std::pair<int, int> start, std::pair<int, int> finish);
	void initWindow();

	sf::RenderWindow* renderWindow;
	sf::VideoMode videoMode;
	sf::Event ev;

	Grid* grid;

	sf::Clock clock;
};