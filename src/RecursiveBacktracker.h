#ifndef RECURSIVEBACKTRACKER_H_INCLUDED
#define RECURSIVEBACKTRACKER_H_INCLUDED

#include <iostream>
#include <utility>
#include <vector>

#include "MazeBase.h"

#include "options.h"
#include "types.h"

using namespace std;

class RecursiveBacktracker : public MazeBase
{
public:

    RecursiveBacktracker(void) : MazeBase() {}

    void Generate(void);

    string GetAscii(void);
    void Draw(void);

private:

    /** Data **/

    vector<pair<int, int> > mStack;

    /** Data Management Functions **/

    bool mCursorUsable(void);
    bool mCanWalk(Direction dir);

    /** Worker Functions **/

    void mWalk(void);
    void mStep(Direction dir);
};

#endif // RECURSIVEBACKTRACKER_H_INCLUDED

