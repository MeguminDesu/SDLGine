#pragma once

#include <SDL.h>
#include <string>

class Screen
{

public:
	Screen();
	~Screen();

	bool Initialize();
	void Refresh();
	void Present();
	void Shutdown();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};

