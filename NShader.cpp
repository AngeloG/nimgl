#include "StdH.h"
#include "NShader.h"

NShader::NShader()
	: m_implVertex(0), m_implFragment(0)
{
}

NShader::NShader(const char* fileID)
{
	Load(fileID);
}

NShader::~NShader()
{
	if (m_implProgram != 0) {
		glDeleteProgram(m_implProgram);
	}
	if (m_implVertex != 0) {
		glDeleteShader(m_implVertex);
	}
	if (m_implFragment != 0) {
		glDeleteShader(m_implFragment);
	}
}

void NShader::Load(const char* fileID)
{
	m_implVertex = CompileShader(NString(fileID) + ".vtx.sha", GL_VERTEX_SHADER);
	m_implFragment = CompileShader(NString(fileID) + ".frg.sha", GL_FRAGMENT_SHADER);

	m_implProgram = glCreateProgram();
	glAttachShader(m_implProgram, m_implVertex);
	glAttachShader(m_implProgram, m_implFragment);
	glLinkProgram(m_implProgram);

	GLint status;
	glGetProgramiv(m_implProgram, GL_LINK_STATUS, &status);
	if (status != GL_TRUE) {
		GLchar buffer[1024];
		GLint len;
		glGetProgramInfoLog(m_implProgram, 1024, &len, buffer);

		printf("Shader program linking failed for '%s':\n%s\n", fileID, buffer);
	}
}

uint32_t NShader::CompileShader(const char* filename, uint32_t implType)
{
	uint32_t ret = glCreateShader(implType);

	NFile f(filename);
	NString strSource = f.ReadAll();
	const char* szSource = strSource;
	glShaderSource(ret, 1, &szSource, nullptr);
	glCompileShader(ret);

	GLint status;
	glGetShaderiv(ret, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) {
		GLchar buffer[1024];
		GLint len;
		glGetShaderInfoLog(ret, 1024, &len, buffer);

		printf("Shader compilation failed for '%s':\n%s\n", filename, buffer);
	}

	return ret;
}

void NShader::Use()
{
	glUseProgram(m_implProgram);
}
