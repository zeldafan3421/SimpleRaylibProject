#include "main.hpp"

const char* FragmentShader = R"(
#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;
uniform vec2 mousePos;

// Output fragment color
out vec4 finalColor;

// NOTE: Add your custom variables here

void main()
{
    // Texel color fetching from texture sampler
    vec4 texelColor = texture(texture0, fragTexCoord);

    // NOTE: Implement here your fragment shader code

    // final color is the color from the texture 
    //    times the tint color (colDiffuse)
    //    times the fragment color (interpolated vertex color)
    vec4 finalColorPre = texelColor*colDiffuse*fragColor;

    finalColor = vec4(mousePos.xy, finalColorPre.zw);
}
)";

Shader shader = {}; 

static void doSetup()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	shader = LoadShaderFromMemory(0, FragmentShader);
}

static void doCleanup()
{
	UnloadShader(shader);
	CloseWindow();
}

int main ()
{
	doSetup();
	
	int mouseLoc = GetShaderLocation(shader, "mousePos");

	while (!WindowShouldClose())
	{
 		auto mousePos = Vector2Normalize(GetMousePosition());
		SetShaderValueV(shader, mouseLoc,&mousePos, SHADER_UNIFORM_VEC2, 1);

		BeginDrawing();
		ClearBackground(BG_COLOR);

		BeginShaderMode(shader);
			DrawRectangle(0,0,WINDOW_WIDTH, WINDOW_HEIGHT, BLUE);
		EndShaderMode();

		EndDrawing();
	}
	
	doCleanup();

	return 0;
}
