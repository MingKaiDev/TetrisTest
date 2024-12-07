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
        DrawText("Hello, Raylib Tetris!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
}