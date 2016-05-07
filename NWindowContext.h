#pragma once

#include "NVertexBuffer.h"
#include "NShader.h"

class NWindowContext
{
private:
	void* m_implContext;

public:
	NVertexBuffer m_vboQuad;
	NShader m_shaQuad;

public:
	NWindowContext(void* pWindow);
	virtual ~NWindowContext();
};
