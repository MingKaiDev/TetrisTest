#pragma once
#include <vector>
#include <raylib.h>

class Grid{
public:
    Grid();
    void InitializeGrid();
    void PrintGrid();
    void DrawGrid();
    bool IsOutSideGrid(int row,int col);
    bool IsCellEmpty(int row,int col);
    int ClearFullRows();
    int grid[20][10];
private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowsDown(int row, int numRows);
    std::vector<Color> colors;
    int numRows;
    int numCols;
    int cellSize;
};