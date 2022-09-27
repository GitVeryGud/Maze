#include "MazeSolver.h"

int main() {

    // "text" -> txt file name
    // "type" -> type of stack being used: "array" or "linked"
    // "startDirection" -> the initial direction the algorithm tests every loop
    //  0 (north) / 1 (east) / 2 (south) / 3 (west)

    maze::MazeSolver("TestMaze", "array", 3);
    return 0;
}

