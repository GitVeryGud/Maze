#ifndef C___PROJECTS_LINKEDSTACK_H
#define C___PROJECTS_LINKEDSTACK_H

#include "MazeCoordinate.h"

namespace stack {

    class LinkedStack
    {
    private:
        struct Node
        {
            Node* previous;
            maze::MazeCoordinate value;
        };

        Node* top;
        Node* temp;
        int size;
        bool isEmpty();

    public:
        LinkedStack();
        void add(maze::MazeCoordinate element);
        maze::MazeCoordinate remove();
        maze::MazeCoordinate show();
        void clear();
        int getSize();
    };

} // stack

#endif //C___PROJECTS_LINKEDSTACK_H
