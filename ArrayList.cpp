#include <stdexcept>
#include "ArrayList.h"

namespace list {
    ArrayList::ArrayList()
    {
        size = 0;
        growthrate = 2;
    }

    void ArrayList::clear()
    {
        size = 0;
    }

    void ArrayList::add(maze::MazeCoordinate element)
    {
        if (isFull()){
            int newCapacity = (int)(getCapacity() * growthrate);
            newCapacity = max(getCapacity() + 1, newCapacity);
            temp = new maze::MazeCoordinate[newCapacity];
            for (int i = 0; i < getCapacity(); i++){
                temp[i] = list[i];
            }
            capacity = newCapacity;
            delete[] list;
            list = temp;

        }
        list[size] = element;
        size ++;
    }

    void ArrayList::add(int index, maze::MazeCoordinate element)
    {
        if (isFull()){
            int newCapacity = (int)(getCapacity() * growthrate);
            newCapacity = max(getCapacity() + 1, newCapacity);
            temp = new maze::MazeCoordinate[newCapacity];
            for (int i = 0; i < getCapacity(); i++){
                temp[i] = list[i];
            }
            capacity = newCapacity;
            delete[] list;
            list = temp;

        }
        if (index < 0 || index > size){
            throw  std::logic_error("Invalid Index: " + index);
        }
        for (int i = size - 1; i >= index; i--){
            list[i + 1] = list[i];
        }
        list[index] = element;
        size ++;
    }

    maze::MazeCoordinate ArrayList::remove(int index)
    {
        if (isEmpty()){
            throw std::logic_error("Empty list (Underflow)");
        }

        if (index < 0 || index >= size){
            throw std::out_of_range("Invalid Index: " + index);
        }

        maze::MazeCoordinate element = list[index];
        for (int i = index; i < size - 1; i++){
            list[i] = list[i+1];
        }
        size--;
        return element;
    }

    maze::MazeCoordinate ArrayList::get(int index)
    {
        if (index < 0 || index >= size){
            throw std::out_of_range("Invalid Index: " + index);
        }
        return list[index];
    }

    void ArrayList::set(int index, maze::MazeCoordinate element)
    {
        if (index < 0 || index >= size){
            throw std::out_of_range("Invalid Index: " + index);
        }
        list[index] = element;
    }

    bool ArrayList::containsCoordinate(int x, int y)
    {
        for (int i = 0; i < size; i++){
            if (list[i].mazeX == x && list[i].mazeY == y){
                return true;
            }
        }
        return false;
    }

    int ArrayList::getSize()
    {
        return size;
    }

    bool ArrayList::isEmpty()
    {
        return size == 0;
    }

    bool ArrayList::isFull()
    {
        return size == getCapacity();
    }

    int ArrayList::getCapacity()
    {
        return capacity;
    }

    int ArrayList::max(int a, int b)
    {
        return (a < b) ? b : a;
    }

} // list