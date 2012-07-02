#ifndef RECURSIVEBACKTRACKER_H_INCLUDED
#define RECURSIVEBACKTRACKER_H_INCLUDED

#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>

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

    /** Data Management Methods **/

    int mGetX(void);
    int mGetY(void);

    vector<dirs::Direction> mUsableDirections(void);
    bool mCursorUsable(void);
    dirs::Direction mGetRandomUsableDirection(void);

    /** Worker Methods **/

    void mWalk(void);
    void mStep(dirs::Direction dir);
    void mBacktrack(void);
};

#endif // RECURSIVEBACKTRACKER_H_INCLUDED

