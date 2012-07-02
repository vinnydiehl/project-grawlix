#include "MazeBase.h"

MazeBase::MazeBase(void)
{
    /**
     * Construct the maze, filling the grid with empty.
    **/

    Clear();
}

void MazeBase::Clear(void)
{
    /**
     * Set every element of the grid to empty.
    **/

    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x)
            mGrid[x][y] = empty;
}

bool MazeBase::IsEmpty(void)
{
    /**
     * Return true if the grid is empty, false otherwise.
    **/

    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x)
            if (mGrid[x][y] != empty)
                return false;

    return true;
}

