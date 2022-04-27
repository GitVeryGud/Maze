#ifndef C___PROJECTS_MAZECOORDINATE_H
#define C___PROJECTS_MAZECOORDINATE_H

namespace maze {
    struct MazeCoordinate {
        int mazeX;
        int mazeY;
        int direction;

        MazeCoordinate(){}

        MazeCoordinate(int x, int y, int dir)
        {
            mazeX = x;
            mazeY = y;
            direction = dir;
        }
    };
} // maze

#endif //C___PROJECTS_MAZECOORDINATE_H
