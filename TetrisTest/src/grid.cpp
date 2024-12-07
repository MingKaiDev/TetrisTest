#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    InitializeGrid();
    colors = GetCellColors();
}
void Grid::InitializeGrid()
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void Grid::PrintGrid()
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::DrawGrid()
{
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            int cellValue = grid[i][j];
            DrawRectangle(j*cellSize+1,i*cellSize+1,cellSize-1,cellSize-1,colors[cellValue]);

        }
    }
} 