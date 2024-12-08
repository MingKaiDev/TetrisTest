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
bool Grid::IsOutSideGrid(int row, int col)
{
    if(row >= 0 && row < numRows && col >= 0 && col < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int col)
{
    if(grid[row][col] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for(int i = numRows-1; i >= 0; i--)
    {
        if(IsRowFull(i))
        {
            ClearRow(i);
            completed++;
        }
        else if(completed > 0)
        {
            MoveRowsDown(i,completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    for(int i = 0; i < numCols; i++)
    {
        if(grid[row][i] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for(int i = 0; i < numCols; i++)
    {
        grid[row][i] = 0;
    }
}

void Grid::MoveRowsDown(int row,int numRows)
{
    for(int i = 0 ; i< numCols; i++)
    {
        grid[row+numRows][i] = grid[row][i];
        grid[row][i] = 0;
    }
}
