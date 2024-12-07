#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
};

void Block::DrawBlock()
{
    std::vector<Position> currentCells = cells[rotationState];
    for(Position item: currentCells)
    {
        DrawRectangle(item.col*cellSize+1,item.row*cellSize+1,cellSize-1,cellSize-1,colors[id]);
    }
};