#include "Path.h"

Path::Path(Cell** grid, std::pair<int, int> start, std::pair<int, int> finish)
{
    this->grid = grid;
    this->start = start;
    this->finish = finish;
    // uncomment for wall
    //createWall(); 
    calculatePath(start.first, start.second);
}

std::stack<std::pair<int, int>> Path::get()
{
    return s;
}

void Path::calculatePath(int row, int col)
{
    q.push({ row, col });
    visited[row][col] = true;

    while (!q.empty())
    {
        auto& cell = q.front();
        int x = cell.first, y = cell.second;

        grid[x][y].coords = { x, y };

        q.pop();

        if (grid[x][y].rs.getFillColor() == sf::Color::Green)
            break;

        for (int i = 0; i < 4; i++)
        {
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if (isValid(adjx, adjy))
            {
                q.push({ adjx, adjy });
                visited[adjx][adjy] = true;
                grid[adjx][adjy].prev = &grid[x][y];
            }
        }
    }
    Cell* pointer = &grid[finish.first][finish.second];

    while (pointer != nullptr)
    {
        s.push({ pointer->coords.first, pointer->coords.second });
        pointer = pointer->prev;
    }
}

bool Path::isValid(int row, int col)
{
	if (row < 0 || col < 0 || row >= ROWS || col >= COLS || grid[row][col].rs.getFillColor() == sf::Color::Blue)
		return false;

	if (visited[row][col])
		return false;

	return true;
}

void Path::createWall()
{
    for (int i = 0; i < 30; i++)
        grid[i][39].rs.setFillColor(sf::Color::Blue);
}