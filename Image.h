#pragma once

#include <string>
#include "Vector.h"
#include "Screen.h"

class Image
{
public:
	Image(int width = 0, int height = 0);
	~Image();

	bool Load(const std::string&, Screen&);
	void Unload();

	void SetPosition(int, int);
	void SetDimesion(int, int);
	void Render(int, int, Screen&);

private:
	SDL_Texture* m_texture;
	Vector<int> m_dimensions;

	float m_angle = 0.0f;
	bool m_hflip = false;
};

