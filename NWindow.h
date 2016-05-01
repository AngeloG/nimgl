#pragma once

#include "StdHP.h"

class NWindow
{
private:
	void* m_implWindow;
	void* m_implContext;

public:
	bool m_bEscapeCloses;

public:
	NWindow();
	NWindow(const char* title);
	NWindow(const char* title, int w, int h);
	virtual ~NWindow();

	virtual bool DoEvents();

	virtual void Clear();
	virtual void Clear(const glm::vec4 &col);
	virtual void Display();

	virtual void Destroy();
};
