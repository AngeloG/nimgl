#pragma once

#include "StdHP.h"

#include "NWindowContext.h"

class NWindow
{
private:
	void* m_implWindow;
	NWindowContext* m_context;

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
