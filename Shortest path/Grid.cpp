#include "Grid.h"

Grid::Grid(std::pair<int, int> start, std::pair<int, int> finish)
{
	init();
	this->start = start;
	this->finish = finish;
	// uncomment for wall
	//this->createWall();
	grid[start.first][start.second].rs.setFillColor(sf::Color::Red);
	grid[finish.first][finish.second].rs.setFillColor(sf::Color::Green);
	this->path = new Path(grid, start, finish);
	this->calculatedPath = path->get();
}

Grid::~Grid()
{
	delete this->path;
	for (int y = 0; y < ROWS; y++)
		delete[] grid[y];
	delete[] grid;
}
bool endPop = true;
void Grid::update()
{
	for (int y = 0; y < ROWS; y++)
	{
		for (int x = 0; x < COLS; x++)
		{
			auto& cell = grid[y][x];
			if (cell.rs.getFillColor() != sf::Color::Red && cell.rs.getFillColor() != sf::Color::Green && cell.rs.getFillColor() != sf::Color::Blue)
				cell.rs.setFillColor(sf::Color::Black);
		}
	}
	if (endPop)
	{
		calculatedPath.pop();
		endPop = false;
	}
	if (!calculatedPath.empty())
	{
		int x = (calculatedPath.top()).first;
		int y = (calculatedPath.top()).second;
		grid[x][y].rs.setFillColor(sf::Color::White);
		calculatedPath.pop();
	}
	if (calculatedPath.empty())
		grid[finish.first][finish.second].rs.setFillColor(sf::Color::White);
}

void Grid::render(sf::RenderTarget& target)
{
	for (int y = 0; y < ROWS; y++)
		for (int x = 0; x < COLS; x++)
			target.draw(grid[y][x].rs);
}

void Grid::init()
{
	grid = new Cell * [ROWS];
	for (int y = 0; y < ROWS; y++)
	{
		grid[y] = new Cell[COLS];
		for (int x = 0; x < COLS; x++)
		{
			grid[y][x].coords = { x, y };
			grid[y][x].rs.setPosition(sf::Vector2f(10.f * x, 10.f * y));
		}
	}
}

void Grid::createWall()
{
	for (int i = 0; i < 30; i++)
		grid[i][39].rs.setFillColor(sf::Color::Blue);
}