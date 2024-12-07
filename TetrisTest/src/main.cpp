#include <raylib.h>
#include "grid.h"



int main() 
{
    InitWindow(300, 600, "Hello, Raylib Tetris!");
    SetTargetFPS(60);

    //Grid Object
    Grid grid = Grid();
    grid.PrintGrid();

    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        grid.DrawGrid();
        EndDrawing();
    }

    CloseWindow();
}