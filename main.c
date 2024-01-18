
#include "raylib.h"
#include "stdio.h"

#define WINDOW_WIDTH  1024
#define WINDOW_HEIGHT  768
#define BLOCK_WIDTH  40
#define BLOCK_HEIGHT  40
#define BLOCK_COLOR BLACK
#define FPS 60

int main(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Flappy Cat");
    SetTargetFPS(FPS);
    float block_x = GetScreenWidth() / 2;
    float block_y = GetScreenHeight() / 2;
    int block_dx = 0;
    int block_dy = 0;
    int block_speed = 100;
    while (!WindowShouldClose()) {
        block_dx = 0;
        block_dy = 0;

        if (IsKeyDown(KEY_A)) {
            block_dx -= 1;
        }
        if (IsKeyDown(KEY_D)) {
            block_dx += 1;
        }
        if (IsKeyDown(KEY_W)) {
            block_dy -= 1;
        }
        if (IsKeyDown(KEY_S)) {
            block_dy += 1;
        }

        float block_new_x = block_x + (block_dx * block_speed * GetFrameTime());
        float block_new_y = block_y + (block_dy * block_speed* GetFrameTime());

        if (block_new_x + BLOCK_WIDTH > WINDOW_WIDTH) {
            block_new_x = WINDOW_WIDTH - BLOCK_WIDTH;
        }
        if (block_new_x < 0) {
            block_new_x = 0;
        }

        if (block_new_y + BLOCK_HEIGHT > WINDOW_HEIGHT) {
            block_new_y = WINDOW_HEIGHT - BLOCK_HEIGHT;
        }
        if (block_new_y < 0) {
            block_new_y = 0;
        }

        block_x = block_new_x;
        block_y = block_new_y;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(block_x, block_y, BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_COLOR);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

