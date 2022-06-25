#pragma once

#include "stdafx.h"

const unsigned int ROWS = 60, COLS = 80;

struct Cell
{
    Cell()
    {
        rs = createRectangleShape();
        coords = { 0, 0 };
        prev = nullptr;
    }
    std::pair<int, int> coords;
    Cell* prev;
    sf::RectangleShape rs;

private:
    sf::RectangleShape createRectangleShape()
    {
        sf::RectangleShape rs;
        rs.setPosition(sf::Vector2f(0, 0));
        rs.setFillColor(sf::Color::Black);
        // Uncomment for outlines
       /* rs.setOutlineColor(sf::Color::White);
        rs.setOutlineThickness(1.f);*/
        rs.setSize(sf::Vector2f(9.f, 9.f));
        return rs;
    }
};

class Path
{
public:
    Path(Cell** grid, std::pair<int, int> start, std::pair<int, int> finish);
    std::stack<std::pair<int, int>> get();
private:
    // Indexes of path
    std::stack<std::pair<int, int>> s;

    // Grid for finding shortest path
    Cell** grid;
    std::pair<int, int> start, finish;

    // Calculating shortest path
    void calculatePath(int row, int col);

    // Filling queue and checking valid cells
    std::queue<std::pair<int, int>> q;
    bool isValid(int row, int col);

    // Storing visited cells
    bool visited[ROWS][COLS]{ false };

    // Direction vectors
    int dRow[4] = { -1, 0, 1, 0 };
    int dCol[4] = { 0, 1, 0, -1 };

    //Create wall
    void createWall();
};