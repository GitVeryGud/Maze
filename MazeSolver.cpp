#include <iostream>
#include "MazeSolver.h"
#include <chrono>

namespace maze {
    MazeSolver::MazeSolver(std::string text, std::string type, int startDirection)
    {
        if (startDirection > 3 || startDirection < 0)
        {
            throw std::invalid_argument("The starting direction need to be 0, 1, 2 or 3");
        }

        textFileName = text;
        textFileName.append(".txt");
        startingDirection = startDirection;

        mazeToCoordinates();

        // Starts the timer
        auto startTime = std::chrono::steady_clock::now();

        if (type == "linked")
        {
            solveLinked();
        }

        else if (type == "array")
        {
            solveArray();
        }

        else
        {
            throw std::invalid_argument("choose either linked or array");
        }

        std::cout<<"Maze Solved!\n";
        // Stops the timer and prints the run time
        auto endTime = std::chrono::steady_clock::now();
        auto runTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
        std::string runTimeString = std::to_string(runTime.count());
        runTimeString.insert(1, ".");
        std::cout<<"Run time: " << runTimeString << " ms\n";


    }

    void MazeSolver::mazeToCoordinates()
    {
        char ch;
        int x = 0;
        int y = 0;
        fileIn.open(textFileName,std::ios::in);
        if(fileIn.is_open()) {
            while (fileIn >> std::noskipws >> ch) {
                if (ch == '#') {
                    mazeList.add(maze::MazeCoordinate(x, y, -1));
                }

                if (ch == 'S') {
                    start = maze::MazeCoordinate(x, y, -1);
                }

                if (ch == 'E') {
                    end = maze::MazeCoordinate(x, y, -1);
                }

                // Advances the horizontal axis
                x++;

                // Advances the vertical axis and resets the horizontal axis
                if (ch == '\n') {
                    x = 0;
                    y++;
                }
            }
            fileIn.close();
            return;
        }

        throw std::invalid_argument("No file found");
    }

    void MazeSolver::solveLinked()
    {
        linkedStack.add(start);
        int dir = startingDirection;
        while (linkedStack.getSize() != 0)
        {

            directionTester(dir, linkedStack.show());

            // If there is a possible path the code goes here
            if (tempCoord.direction != -1)
            {
                linkedStack.add(tempCoord);
                dir = startingDirection;
            }

                // if he's completely blocked the code goes here
            else
            {
                tempCoord = linkedStack.remove();
                mazeList.add(tempCoord);
                dir = tempCoord.direction;
            }

            if (equalCoordinates(linkedStack.show(), end))
            {
                break;
            }
        }

        // If the stack empties it means the maze is impossible
        if (linkedStack.getSize() == 0)
        {
            throw std::logic_error("Maze has no exit");
        }

        // Empties the stack
        while (linkedStack.getSize() != 0)
        {
            solution.add(linkedStack.remove());
        }

        // Creates the solved maze text file
        fileOut.open("SolvedMaze.txt", std::ios::out);
        fileIn.open(textFileName, std::ios::in);
        char ch;
        int x = 0;
        int y = 0;

        if(fileIn.is_open() && fileOut.is_open())
        {
            while (fileIn >> std::noskipws >> ch) {
                if (solution.containsCoordinate(x,y) && ch != 'S' && ch != 'E')
                {
                    fileOut << '-';
                }

                else
                {
                    fileOut << ch;
                }

                // Advances the horizontal axis
                x++;

                // Advances the vertical axis and resets the horizontal axis
                if (ch == '\n') {
                    x = 0;
                    y++;
                }
            }
            fileIn.close();
            fileOut.close();
        }

    }

    void MazeSolver::solveArray()
    {
        arrayStack.add(start);
        int dir = startingDirection;
        while (arrayStack.getSize() != 0)
        {

            directionTester(dir, arrayStack.show());

            // If there is a possible path the code goes here
            if (tempCoord.direction != -1)
            {
                arrayStack.add(tempCoord);
                dir = startingDirection;
            }

            // if he's completely blocked the code goes here
            else
            {
                tempCoord = arrayStack.remove();
                mazeList.add(tempCoord);
                dir = tempCoord.direction;
            }

            if (equalCoordinates(arrayStack.show(), end))
            {
                break;
            }
        }

        // If the stack empties it means the maze is impossible
        if (arrayStack.getSize() == 0)
        {
            throw std::logic_error("Maze has no exit");
        }

        // Empties the stack
        while (arrayStack.getSize() != 0)
        {
            solution.add(arrayStack.remove());
        }

        // Creates the solved maze text file
        fileOut.open("SolvedMaze.txt", std::ios::out);
        fileIn.open(textFileName, std::ios::in);
        char ch;
        int x = 0;
        int y = 0;

        if(fileIn.is_open() && fileOut.is_open())
        {
            while (fileIn >> std::noskipws >> ch) {
                if (solution.containsCoordinate(x,y) && ch != 'S' && ch != 'E')
                {
                    fileOut << '-';
                }

                else
                {
                    fileOut << ch;
                }

                // Advances the horizontal axis
                x++;

                // Advances the vertical axis and resets the horizontal axis
                if (ch == '\n') {
                    x = 0;
                    y++;
                }
            }
            fileIn.close();
            fileOut.close();
        }

    }

    int MazeSolver::directionRotation(int dir)
    {
        // if the current direction is one before the startingDirection it returns
        // a invalid value to restart the loop
        if (dir == (startingDirection + 3)%4)
        {
            return -1;
        }

        // else it works as normal
        return (dir + 1)%4;
    }

    // 0 (North) / 1 (East) / 2 (South) / 3 (West) / -1 (Means that the code looped through the directions)
    void MazeSolver::directionTester(int dir, maze::MazeCoordinate current)
    {
        int x = current.mazeX;
        int y = current.mazeY;

        if (dir == -1)
        {
            tempCoord = maze::MazeCoordinate(x, y, dir);
            return;
        }

        if (dir == 0)
        {
            y = current.mazeY - 1;
        }

        if (dir == 1)
        {
            x = current.mazeX + 1;
        }

        if (dir == 2)
        {
            y = current.mazeY + 1;
        }

        if (dir == 3)
        {
            x = current.mazeX - 1;
        }

        // checks if there is a wall there or if you just came from there
        if (mazeList.containsCoordinate(x,y) ||
        current.direction == (dir +2)%4 && !equalCoordinates(current, start))
        {
            directionTester(directionRotation(dir), current);
        }

        else
        {
            tempCoord = maze::MazeCoordinate(x, y, dir);
            return;
        }
    }

    bool MazeSolver::equalCoordinates(maze::MazeCoordinate coord1, maze::MazeCoordinate coord2)
    {
        if (coord1.mazeX == coord2.mazeX && coord1.mazeY == coord2.mazeY)
        {
            return true;
        }

        return false;
    }

} // maze