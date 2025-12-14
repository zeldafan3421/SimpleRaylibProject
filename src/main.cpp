#include "main.hpp"

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BG_COLOR);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
