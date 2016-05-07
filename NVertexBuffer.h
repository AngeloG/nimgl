#pragma once

#include "StdHP.h"

#include "NVertices.h"

class NVertexBuffer
{
private:
	uint32_t m_implBuffer;
	uint32_t m_implArray;
	uint32_t m_implElements;

public:
	uint32_t m_ctVertices;
	uint32_t m_ctIndices;

public:
	NVertexBuffer();
	virtual ~NVertexBuffer();

	void LoadBuffer(const NVertex2D* pBuffer, uint32_t count);
	void LoadBuffer(const NVertex3D* pBuffer, uint32_t count);
	void LoadElements(const uint32_t* pBuffer, uint32_t count);

	void DrawArrays();
	void DrawElements();
};
