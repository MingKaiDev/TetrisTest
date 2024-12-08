#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
    public:
        Game();
        void Draw();
        void RotateBlock();
        void HandleInput();
        void MoveBlockDirection(int x, int y);
        bool gameOver;
        int score;

    private:
        Block GetRandomBlock();
        void GetAllBlocks();
        bool IsBlockOutside();
        void LockBlock();
        bool BlockFits();
        void Reset();
        void UpdateScore(int linesCleared, int MoveDownPoints);
        std::vector<Block> blocks;
        Grid grid;
        Block currentBlock;
        Block nextBlock;
};