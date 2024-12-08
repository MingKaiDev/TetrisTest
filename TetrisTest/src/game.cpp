#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
};

Block Game::GetRandomBlock()
{
    if(blocks.empty()){
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

void Game::HandleInput(){
    if(IsKeyPressed(KEY_LEFT)){
        MoveBlockDirection(0,-1);
    }
    if(IsKeyPressed(KEY_RIGHT)){
        MoveBlockDirection(0,1);
    }
    if(IsKeyPressed(KEY_DOWN)){
        MoveBlockDirection(1,0);
    }
}

void Game::MoveBlockDirection(int x,int y){
    currentBlock.MoveBlock(x,y);
    if(IsBlockOutside()){
        currentBlock.MoveBlock(-x,-y);
    }
}

bool Game::IsBlockOutside()
{
    std::vector<Position> currentCells = currentBlock.GetPositions();
    for(Position item: currentCells)
    {
        if(grid.IsOutSideGrid(item.row,item.col))
        {
            return true;
        }
    }
    return false;
};

void Game::Draw(){
    grid.DrawGrid();
    currentBlock.DrawBlock();
}