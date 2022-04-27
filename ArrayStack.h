#ifndef C___PROJECTS_ARRAYSTACK_H
#define C___PROJECTS_ARRAYSTACK_H

#include "MazeCoordinate.h"

namespace stack {

    class ArrayStack
    {
    private:
        int top;
        maze::MazeCoordinate *stacks = new maze::MazeCoordinate[8];
        maze::MazeCoordinate *temp;
        int capacity = 8;
        double growthRate;

        int getCapacity();
        bool isFull();
        bool isEmpty();

    public:
        ArrayStack();
        void add(maze::MazeCoordinate element);
        maze::MazeCoordinate remove();
        maze::MazeCoordinate show();
        void clear();
        int getSize();
        int max(int a, int b);
    };

} // stack

#endif //C___PROJECTS_ARRAYSTACK_H
