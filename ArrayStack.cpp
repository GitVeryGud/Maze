#include <stdexcept>
#include "ArrayStack.h"

namespace stack {
    ArrayStack::ArrayStack()
    {
        top = -1;
        growthRate = 2;
    }

    int ArrayStack::getCapacity()
    {
        return capacity;
    }

    bool ArrayStack::isEmpty()
    {
        return top < 0;
    }

    bool ArrayStack::isFull()
    {
        return top + 1 >= getCapacity();
    }

    int ArrayStack::getSize()
    {
        return (top + 1);
    }

    void ArrayStack::clear()
    {
        top = -1;
    }

    maze::MazeCoordinate ArrayStack::show()
    {
        if (!isEmpty())
        {
            return stacks[top];
        }

        else
            throw std::logic_error("Empty stack (Underflow)");
    }

    maze::MazeCoordinate ArrayStack::remove()
    {
        if (isEmpty()){
            throw std::logic_error("Empty stack (Underflow)");
        }

        top--;
        return stacks[top + 1];
    }

    void ArrayStack::add(maze::MazeCoordinate element)
    {
        if (isFull()){
            int newCapacity = (int)(getCapacity() * growthRate);
            newCapacity = max(getCapacity() + 1, newCapacity);
            temp = new maze::MazeCoordinate[newCapacity];
            for (int i = 0; i < getCapacity(); i++){
                temp[i] = stacks[i];
            }
            delete[] stacks;
            stacks = temp;
            capacity = newCapacity;

        }

        top++;
        stacks[top] = element;
    }

    int ArrayStack::max(int a, int b)
    {
        return (a < b) ? b : a;
    }




} // stack