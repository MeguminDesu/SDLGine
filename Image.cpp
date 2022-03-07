#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "Image.h"
#include "Screen.h"

Image::Image(int width, int height)
{
	SetDimesion(width, height);
}

Image::~Image()
{ }

bool Image::Load(const std::string& filename, Screen& screen)
{
	SDL_Surface* imageData = IMG_Load(filename.c_str());
	if (!imageData) std::cout << "Error Loading file: " << filename << std::endl;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(screen.GetRenderer(), imageData);
	m_texture = texture;

	return true;
}

void Image::Unload()
{ }

void Image::SetPosition(int x, int y)
{ }

void Image::SetDimesion(int w, int h)
{
	m_dimensions.x = w;
	m_dimensions.y = h;
}

void Image::Render(int x, int y, Screen& screen)
{
	SDL_Rect src;
	SDL_Rect dst;

	src.x = 0;
	src.y = 0;
	src.w = m_dimensions.x;
	src.h = m_dimensions.y;

	dst.x = 0;
	dst.y = 0;
	dst.w = m_dimensions.x;
	dst.h = m_dimensions.y;

	SDL_Point centerPoint;
	centerPoint.x = m_dimensions.x / 2;
	centerPoint.y = m_dimensions.y / 2;
	SDL_RenderCopyEx(screen.GetRenderer(), m_texture,
		&src, &dst, m_angle, &centerPoint,
		m_hflip ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE);

}