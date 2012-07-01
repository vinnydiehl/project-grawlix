#ifndef MAZEBASE_H_INCLUDED
#define MAZEBASE_H_INCLUDED

#include "options.h"
#include "types.h"

class MazeBase
{
public:

    MazeBase(Cell fill=empty);

    virtual void abstract() = 0;

protected:

    Cell mGrid[SIZE][SIZE];
};

#endif // MAZEBASE_H_INCLUDED

