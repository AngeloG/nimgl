#pragma once

#include "StdHP.h"

class NShader
{
private:
	uint32_t m_implVertex;
	uint32_t m_implFragment;
	uint32_t m_implProgram;

public:
	NShader();
	NShader(const char* fileID);
	virtual ~NShader();

	void Load(const char* fileID);
	uint32_t CompileShader(const char* filename, uint32_t implType);

	void Use();
};
