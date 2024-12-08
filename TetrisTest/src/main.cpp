#include <raylib.h>
#include <iostream>
#include "game.h"
#include "colors.h"

double lastUpdateTime = 0;

bool EventTriggered(double time)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= time)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() 
{
    InitWindow(500, 620, "Raylib Tetris!");
    SetTargetFPS(60);

    Game game = Game();

    while(WindowShouldClose() == false)
    {
        game.HandleInput();
        if(EventTriggered(0.2)){
            game.MoveBlockDirection(1,0);
        }
        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawTextEx(GetFontDefault(), "Next", Vector2{360,175}, 38, 2, WHITE);
        if(game.gameOver)
        {
            DrawTextEx(GetFontDefault(), "Game Over", Vector2{320,450}, 36, 2, WHITE);
            DrawTextEx(GetFontDefault(), "Press Enter", Vector2{325,490}, 26, 2, WHITE);
        }
        DrawRectangleRounded({320,55,170,60},0.3,6,lightBlue);
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(GetFontDefault(), scoreText, 38, 2);
        DrawTextEx(GetFontDefault(), scoreText, Vector2{320+(170-textSize.x)/2,65}, 38, 2, WHITE);
        DrawTextEx(GetFontDefault(), "Score", Vector2{350,15}, 38, 2, WHITE);
        DrawRectangleRounded({320,215,170,180},0.3,6,lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}