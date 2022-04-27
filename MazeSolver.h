#ifndef C___PROJECTS_MAZESOLVER_H
#define C___PROJECTS_MAZESOLVER_H

#include <fstream>
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "ArrayList.h"

namespace maze {

    class MazeSolver {
    private:
        std::string textFileName;
        std::fstream fileIn;
        std::fstream fileOut;
        stack::ArrayStack arrayStack;
        stack::LinkedStack linkedStack;
        list::ArrayList mazeList;
        list::ArrayList solution;
        maze::MazeCoordinate start, end, tempCoord;
        int startingDirection;

        void mazeToCoordinates();
        void solveLinked();
        void solveArray();
        int directionRotation(int dir);
        void directionTester(int dir, maze::MazeCoordinate current);
        bool equalCoordinates(maze::MazeCoordinate coord1, maze::MazeCoordinate coord2);

    public:
        // type is the type of stack that will be used -> linked / array
        // start_direction is the direction that will be tested first ->
        // 0 (North) / 1 (East) / 2 (South) / 3 (West)
        MazeSolver(std::string text, std::string type, int startDirection);

    };

} // maze

#endif //C___PROJECTS_MAZESOLVER_H
