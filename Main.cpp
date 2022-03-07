#include <iostream>

#include "Vector.h"
#include "Input.h";

#include "Screen.h";
#include "GameManager.h"
#include "Mouse.h";
#include "Image.h"

#include <SDL.h>
#include <SDL_image.h>

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

bool isgamerunning = true;

int main(int argc, char* argv[])
{
	Screen screen;
	screen.Initialize();

	GameManager gameManager;
	gameManager.Initialize();

	Mouse mouse;
	mouse.Initialize();

	Image sprite(64, 64);
	sprite.Load("images/metal_bladekeeper.png", screen);

	while (isgamerunning)
	{
		screen.Refresh();

		Input::Instance()->Update();
		mouse.Update();

		// Close Window
		if (Input::Instance()->IsWindowClosed())
		{ isgamerunning = false; }

		sprite.Render(0, 0, screen);
		screen.Present();
	}

	// ==================================================

	screen.Shutdown();
	sprite.Unload();

	// ==================================================

	return 0;
}