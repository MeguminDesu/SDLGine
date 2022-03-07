#include <iostream>

#include "Vector.h"
#include "Input.h";

#include "Screen.h";
#include "GameManager.h"
#include "Mouse.h";

#include <SDL.h>

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

	while (isgamerunning)
	{
		screen.Refresh();

		Input::Instance()->Update();
		mouse.Update();

		// Close Window
		if (Input::Instance()->IsWindowClosed())
		{
			isgamerunning = false;
		}

		screen.Present();
	}

	// ==================================================

	screen.Shutdown();

	// ==================================================

	return 0;
}