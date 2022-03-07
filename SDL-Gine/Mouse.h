#pragma once
class Mouse
{
public:
	Mouse();
	~Mouse();

	bool Initialize();
	void Update();

	bool m_isMouseDown;
};

