#include "RecursiveBacktracker.h"

/** Public Methods **/

void RecursiveBacktracker::Generate(void)
{
    /**
     * Generate the maze using the "recursive backtracker" algorithm.
    **/

    // Make sure we have a clean slate before we start.
    Clear();

    // Initialize the stack with a random coordinate.
    mStack.push_back(make_pair((rand() % WIDTH) + 1, (rand() % HEIGHT) + 1));

    do
    {
        mWalk();
        mBacktrack();
    }
    while (!mStack.empty());
}

string RecursiveBacktracker::GetAscii(void)
{
    /**
     * Return the maze in ASCII format.
     *
     * East walls are " |", south walls are "_.".
    **/

    string output;

    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x)
            output += mGrid[x][y] == vertical
                      ? " |"
                      : mGrid[x][y] == horizontal
                        ? "_."
                        // If there was a screw up and the cell is blank (or
                        // if this is called while the grid is still blank and
                        // all of the cells are blank), use "XX" so we know
                        // what's up.
                        : "XX";

    return output;
}
void RecursiveBacktracker::Draw(void)
{
    /**
     * Print the ASCII form of the maze to the console.
    **/

    cout << GetAscii() << endl;
}

/** Data Management Methods **/

int RecursiveBacktracker::mGetX(void)
{
    /**
     * Return the X coordinate of the cursor.
    **/

    return mStack.back().first;
}
int RecursiveBacktracker::mGetY(void)
{
    /**
     * Return the Y coordinate of the cursor.
    **/

    return mStack.back().second;
}

vector<Direction> RecursiveBacktracker::mUsableDirections(void)
{
    /**
     * Return a vector containing all of the usable directions.
     *
     * A direction is usable if it leads to an empty adjacent cell.
    **/

    vector<Direction> dirs;

    // up
    if (mGetY() > 0 && mGrid[mGetX()][mGetY()-1] != empty)
        dirs.push_back(up);
    // right
    if (mGetX() < WIDTH && mGrid[mGetX()+1][mGetY()] != empty)
        dirs.push_back(right);
    // down
    if (mGetY() < HEIGHT && mGrid[mGetX()][mGetY()+1] != empty)
        dirs.push_back(down);
    // left
    if (mGetX() > 0 && mGrid[mGetX()-1][mGetY()] != empty)
        dirs.push_back(left);

    return dirs;
}
bool RecursiveBacktracker::mCursorUsable(void)
{
    /**
     * Return true if the cursor has an adjacent empty cell.
    **/

    return mUsableDirections().size() > 0;
}
Direction RecursiveBacktracker::mGetRandomUsableDirection(void)
{
    /**
     * From the usable directions, return one at random.
    **/

    vector<Direction> dirs = mUsableDirections();
    return dirs[rand() % dirs.size()];
}

/** Worker Methods **/

void RecursiveBacktracker::mWalk(void)
{
    /**
     * Perform a "drunkard's walk" on the grid.
     *
     * The cursor will move about the grid, carving a path along the way,
     * and advancing to a random adjacent cell at each stop. It will only
     * advance to cells that it hasn't touched, and if it hits a dead end,
     * the walk will finish so that backtracking may begin.
    **/

    while (mCursorUsable())
        mStep(mGetRandomUsableDirection());
}
void RecursiveBacktracker::mStep(Direction dir)
{
    /**
     * Advance the cursor in a particular direction.
     *
     * Move the cursor in the direction specified in the parameters. This
     * does no bounds checking, it will blindly attempt to take the step that
     * it is told to, so make sure that it is safe to run this method before
     * doing so. This assigns the data in mGrid and pushes to mStack.
    **/

    /**
     * Two lines of code in each switch case.
     * The first will add the new location of the cursor to the stack.
     * The second then assigns the proper data to the grid.
     * If we're moving up or down, the path we carve is vertical; if we're
     * moving left or right, carve a horizontal path.
    **/
    switch (dir)
    {
        case up:
            mStack.push_back(make_pair(mGetX(), mGetY() - 1));
            mGrid[mGetX()][mGetY()] = vertical;
            break;
        case right:
            mStack.push_back(make_pair(mGetX() + 1, mGetY()));
            mGrid[mGetX()][mGetY()] = horizontal;
            break;
        case down:
            mStack.push_back(make_pair(mGetX(), mGetY() + 1));
            mGrid[mGetX()][mGetY()] = vertical;
            break;
        case left:
            mStack.push_back(make_pair(mGetX() - 1, mGetY()));
            mGrid[mGetX()][mGetY()] = horizontal;
            break;
    }
}

void RecursiveBacktracker::mBacktrack(void)
{
    /**
     * Pop off of the stack until the cursor can walk again.
     *
     * Also stop if the stack is empty.
    **/

    while (!mCursorUsable() && mStack.size() > 0)
        mStack.pop_back();
}

