#pragma once

#include "StdHP.h"

class NShader
{
private:
	uint32_t m_implVertex;
	uint32_t m_implFragment;

public:
	NShader(const char* fileID);
	virtual ~NShader();
};
