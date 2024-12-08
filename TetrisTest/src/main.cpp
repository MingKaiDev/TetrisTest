#include <raylib.h>
#include "game.h"

int main() 
{
    InitWindow(300, 600, "Hello, Raylib Tetris!");
    SetTargetFPS(60);

    Game game = Game();

    while(WindowShouldClose() == false)
    {
        game.HandleInput();
        BeginDrawing();
        ClearBackground(DARKBLUE);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}