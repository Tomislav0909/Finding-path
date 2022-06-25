#include "Game.h"

void setCoord(char c, int& coord, const char* s, int max)
{
    // Checking input
    do
    {
        std::cout << "Enter " << c << " " << s << ": ";
        std::cin >> coord;
    } while (coord < 1 || coord > max);
}

std::pair<int, int> set(char c)
{
    int row, col;
    // Setting coords according to max value
    setCoord(c, row, "row", ROWS);
    setCoord(c, col, "col", COLS);
    return { row - 1, col - 1 };
}

int main()
{
    auto start = set('A'), finish = set('B');

    Game game(start, finish);
    game.run();

    return 0;
}