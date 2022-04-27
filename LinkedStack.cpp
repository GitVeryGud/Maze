#include <cstddef>
#include <iostream>
#include "LinkedStack.h"

namespace stack {

    LinkedStack::LinkedStack()
    {
        top = NULL;
        size = 0;
    }

    bool LinkedStack::isEmpty()
    {
        return size <= 0;
    }

    void LinkedStack::add(maze::MazeCoordinate element)
    {
        Node *node = new Node();
        node->previous = top;
        node->value = element;
        top = node;
        size++;
    }

    maze::MazeCoordinate LinkedStack::remove()
    {
        if (isEmpty()) throw std::logic_error("Empty stack (Underflow)");
        maze::MazeCoordinate currentValue = top->value;
        temp = top;
        top = top->previous;
        delete temp;
        size--;
        return currentValue;
    }

    maze::MazeCoordinate LinkedStack::show()
    {
        if (top != NULL)
            return top->value;
        else
            throw std::logic_error("Empty stack (Underflow)");
    }

    void LinkedStack::clear()
    {
        top = NULL;
    }

    int LinkedStack::getSize()
    {
        return size;
    }
} // stack