#include "Game.h"

Game::Game(std::pair<int, int> start, std::pair<int, int> finish)
{
	this->initVariables(start, finish);
	this->initWindow();
}

Game::~Game()
{
	delete this->grid;
	delete this->renderWindow;
}

void Game::run()
{
	while (this->renderWindow->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::update()
{
	this->updatePollEvents();
	if (clock.getElapsedTime().asMilliseconds() > 100)
	{
		this->grid->update();
		clock.restart();
	}
}

void Game::updatePollEvents()
{
	while (this->renderWindow->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->renderWindow->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->renderWindow->close();
			break;
		}
	}
}

void Game::render()
{
	this->renderWindow->clear();
	this->grid->render(*this->renderWindow);
	this->renderWindow->display();
}

void Game::initVariables(std::pair<int, int> start, std::pair<int, int> finish)
{
	this->renderWindow = nullptr;
	this->grid = new Grid(start, finish);
}

void Game::initWindow()
{
	this->videoMode.width = 799;
	this->videoMode.height = 599;
	this->renderWindow = new sf::RenderWindow(this->videoMode, "Path finding", sf::Style::Titlebar | sf::Style::Close);
}