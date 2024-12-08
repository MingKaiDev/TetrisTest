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
        void RotateBlock();
        void HandleInput();
        void MoveBlockDirection(int x, int y);
        Grid grid;
        bool gameOver;

    private:
        bool IsBlockOutside();
        void LockBlock();
        bool BlockFits();
        void Reset();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};