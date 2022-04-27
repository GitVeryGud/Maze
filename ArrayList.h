#ifndef C___PROJECTS_ARRAYLIST_H
#define C___PROJECTS_ARRAYLIST_H

#include "MazeCoordinate.h"

namespace list {

    class ArrayList {
    private:
        int size;
        double growthrate;
        int capacity = 8;
        maze::MazeCoordinate *list = new maze::MazeCoordinate[8];
        maze::MazeCoordinate *temp;
        bool isFull();

    public:
        ArrayList();
        void clear();
        void add(maze::MazeCoordinate element);
        void add(int index, maze::MazeCoordinate element);
        maze::MazeCoordinate remove(int index);
        maze::MazeCoordinate get(int index);
        void set(int index, maze::MazeCoordinate element);
        bool containsCoordinate(int x, int y);
        int getSize();
        bool isEmpty();
        int getCapacity();
        int max(int a, int b);
    };

} // list

#endif //C___PROJECTS_ARRAYLIST_H
