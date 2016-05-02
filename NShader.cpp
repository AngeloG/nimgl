#include "StdH.h"
#include "NShader.h"

NShader::NShader(const char* fileID)
{
	m_implVertex = 0;
	m_implFragment = 0;
}

NShader::~NShader()
{
}
