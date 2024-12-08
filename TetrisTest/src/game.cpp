#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
};

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
};

void Game::GetAllBlocks()
{
    blocks.push_back(IBlock());
    blocks.push_back(JBlock());
    blocks.push_back(LBlock());
    blocks.push_back(OBlock());
    blocks.push_back(SBlock());
    blocks.push_back(TBlock());
    blocks.push_back(ZBlock());
};

void Game::HandleInput()
{
    if(gameOver && IsKeyPressed(KEY_ENTER))
    {
        gameOver = false;
        Reset();
    }
    if (IsKeyPressed(KEY_LEFT))
    {
        MoveBlockDirection(0, -1);
    }
    if (IsKeyPressed(KEY_RIGHT))
    {
        MoveBlockDirection(0, 1);
    }
    if (IsKeyPressed(KEY_DOWN))
    {
        MoveBlockDirection(1, 0);
    }
    if (IsKeyPressed(KEY_UP))
    {
        RotateBlock();
    }
}

void Game::MoveBlockDirection(int x, int y)
{
    if (gameOver == false)
    {
        currentBlock.MoveBlock(x, y);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.MoveBlock(-x, -y);
            if (x == 1 && y == 0)
            {
                LockBlock();
            }
        }
    }
}

bool Game::IsBlockOutside()
{
    std::vector<Position> currentCells = currentBlock.GetPositions();
    for (Position item : currentCells)
    {
        if (grid.IsOutSideGrid(item.row, item.col))
        {
            return true;
        }
    }
    return false;
};

void Game::Draw()
{
    grid.DrawGrid();
    currentBlock.DrawBlock();
}

void Game::RotateBlock()
{
    currentBlock.Rotate();
    if (IsBlockOutside())
    {
        currentBlock.Unrotate();
    }
}
void Game::LockBlock()
{
    std::vector<Position> currentCells = currentBlock.GetPositions();
    for (Position item : currentCells)
    {
        grid.grid[item.row][item.col] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if (BlockFits() == false)
    {
        gameOver = true;
        return;
    }
    nextBlock = GetRandomBlock();
    grid.ClearFullRows();
}

bool Game::BlockFits()
{
    std::vector<Position> currentCells = currentBlock.GetPositions();
    for (Position item : currentCells)
    {
        if (grid.IsCellEmpty(item.row, item.col) == false)
        {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.InitializeGrid();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}
