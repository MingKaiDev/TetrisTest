#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    colOffset = 0;
    MoveBlock(0,3);
};

void Block::DrawBlock(int row, int col)
{
    std::vector<Position> currentCells = GetPositions();
    for(Position item: currentCells)
    {
        DrawRectangle(item.col*cellSize+col,item.row*cellSize+row,cellSize-1,cellSize-1,colors[id]);
    }
};

void Block::MoveBlock(int row, int col)
{
    rowOffset += row;
    colOffset += col;
}

void Block::Rotate() {
    rotationState++;
    if(rotationState >= (int)cells.size())
    {
        rotationState = 0;
    }
}
void Block::Unrotate()
{
    rotationState--;
    if(rotationState < 0)
    {
        rotationState = cells.size()-1;
    }
};

std::vector<Position> Block::GetPositions()
{
    std::vector<Position> currentCells = cells[rotationState];
    std::vector<Position> positions;
    for(Position item: currentCells)
    {
        Position newPosition = Position(item.row+rowOffset,item.col+colOffset);
        positions.push_back(newPosition);
    }
    return positions;
};