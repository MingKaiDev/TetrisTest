#include "grid.h"
#include <iostream>
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
            DrawRectangle(j*cellSize,i*cellSize,cellSize,cellSize,colors[cellValue]);
            
        }
    }
} 

std::vector<Color> Grid::GetCellColors()
{
    Color darkGREY = {26,32,40,255};
    Color green = {47,240,47,255};
    Color red = {232,18,18,255};
    Color orange = {232,126,18,255};
    Color blue = {18,18,232,255};
    Color yellow = {232,232,18,255};
    Color purple = {126,18,232,255};
    Color cyan = {18,232,232,255};

    return {darkGREY, green, red, orange, yellow,purple,cyan,blue};
}