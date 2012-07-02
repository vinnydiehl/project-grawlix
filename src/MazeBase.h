#ifndef MAZEBASE_H_INCLUDED
#define MAZEBASE_H_INCLUDED

#include "options.h"
#include "types.h"

class MazeBase
{
public:

    MazeBase(void);

    void Clear(void);
    bool IsEmpty(void);

protected:

    Cell mGrid[WIDTH][HEIGHT];
};

#endif // MAZEBASE_H_INCLUDED

