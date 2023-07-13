#include "raylib.h"

int main(int argc, char const *argv[]) {

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    InitWindow(1280, 800, "Game");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawFPS(5, 5);

        EndDrawing();
    }

    return 0;
}