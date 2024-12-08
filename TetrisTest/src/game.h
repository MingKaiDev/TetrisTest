#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
    public:
        Game();
        Block GetRandomBlock();
        void GetAllBlocks();
        void Draw();
        void HandleInput();
        void MoveBlockDirection(int x, int y);
        Grid grid;

    private:
        bool IsBlockOutside();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};