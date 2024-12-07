#pragma once
#include <vector>
#include <raylib.h>

class Grid{
public:
    Grid();
    void InitializeGrid();
    void PrintGrid();
    void DrawGrid();
    int grid[20][10];
private:
    std::vector<Color> colors;
    int numRows;
    int numCols;
    int cellSize;
    
};