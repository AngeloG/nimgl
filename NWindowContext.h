#pragma once

#include "NVertexBuffer.h"

class NWindowContext
{
private:
	void* m_implContext;

public:
	NVertexBuffer m_vboQuad;

public:
	NWindowContext(void* pWindow);
	virtual ~NWindowContext();
};
