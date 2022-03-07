#include "Mouse.h"

#include <iostream>
#include <SDL.h>

#include "Input.h"

Mouse::Mouse()
{
	m_isMouseDown = false;
}

Mouse::~Mouse()
{ }

bool Mouse::Initialize()
{
	return true;
}

void Mouse::Update()
{

	auto mousePos = Input::Instance()->GetMousePosition();
	auto mouseMotion = Input::Instance()->GetMouseMotion();

	// Mouse Click
	if (Input::Instance()->IsMouseClicked(HM_MOUSE_LEFT) && m_isMouseDown == false)
	{
		m_isMouseDown = true;
		std::cout << "Mouse Click" << std::endl;
	}
	if (Input::Instance()->IsMouseClicked(HM_MOUSE_LEFT) == false)
	{
		m_isMouseDown = false;
	}
}