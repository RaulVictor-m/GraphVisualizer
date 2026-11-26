#include <raylib.h>

int main(void) {
    InitWindow(500, 500, "hello");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
    }
    return 0;
}
