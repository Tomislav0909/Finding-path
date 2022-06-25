#pragma once

#include "Path.h"

class Grid
{
public:
    Grid(std::pair<int, int> start, std::pair<int, int> finish);
    ~Grid();
    void render(sf::RenderTarget& target);
    void update();
private:
    void init();
    Cell** grid;

    Path* path;
    std::stack<std::pair<int, int>> calculatedPath;
    std::pair<int, int> start, finish;

    void createWall();
};