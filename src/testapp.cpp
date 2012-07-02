// Test application for the maze.

#include "RecursiveBacktracker.h"

int main(void)
{
    RecursiveBacktracker *maze = new RecursiveBacktracker();

    maze->Generate();
    maze->Draw();

    return 0;
}

