#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block{
    public:
    Block();
    void DrawBlock();
    void MoveBlock(int row, int col);
    std::vector<Position> GetPositions();
    int id;
    std::map<int,std::vector<Position>> cells;
    private:
        int cellSize;
        int rotationState;
        int rowOffset;
        int colOffset;
        std::vector<Color> colors;
};