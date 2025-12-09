#include "raylib.h"

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;
const char *WINDOW_TITLE = "Raylib project"; 
constexpr Color BG_COLOR = WHITE;

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
