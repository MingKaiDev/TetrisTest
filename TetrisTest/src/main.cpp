#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main() 
{
    InitWindow(300, 600, "Hello, Raylib Tetris!");
    SetTargetFPS(60);

    //Grid Object
    Grid grid = Grid();
    grid.PrintGrid();
    SBlock block = SBlock();

    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        grid.DrawGrid();
        block.DrawBlock();
        EndDrawing();
    }

    CloseWindow();
}