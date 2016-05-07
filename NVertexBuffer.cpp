#include "StdH.h"
#include "NVertexBuffer.h"

NVertexBuffer::NVertexBuffer()
{
	m_implBuffer = 0;
	m_implArray = 0;
	m_implElements = 0;

	m_ctVertices = 0;
	m_ctIndices = 0;
}

NVertexBuffer::~NVertexBuffer()
{
	if (m_implBuffer != 0) {
		glDeleteBuffers(1, (GLuint*)&m_implBuffer);
	}
	if (m_implArray != 0) {
		glDeleteVertexArrays(1, (GLuint*)&m_implArray);
	}
	if (m_implElements != 0) {
		glDeleteBuffers(1, (GLuint*)&m_implElements);
	}
}

void NVertexBuffer::LoadBuffer(const NVertex2D* pBuffer, uint32_t count)
{
	glGenVertexArrays(1, &m_implArray);
	glBindVertexArray(m_implArray);

	glGenBuffers(1, (GLuint*)&m_implBuffer);
	glBindBuffer(GL_VERTEX_ARRAY, (GLuint)m_implBuffer);
	glBufferData(GL_VERTEX_ARRAY, sizeof(NVertex2D) * count, pBuffer, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_INT, GL_FALSE, sizeof(NVertex2D), (void*)offsetof(NVertex2D, point));
	glEnableVertexAttribArray(0);

	m_ctVertices = count;
}

void NVertexBuffer::LoadBuffer(const NVertex3D* pBuffer, uint32_t count)
{
	glGenVertexArrays(1, &m_implArray);
	glBindVertexArray(m_implArray);

	glGenBuffers(1, (GLuint*)&m_implBuffer);
	glBindBuffer(GL_VERTEX_ARRAY, (GLuint)m_implBuffer);
	glBufferData(GL_VERTEX_ARRAY, sizeof(NVertex3D) * count, pBuffer, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(NVertex3D), (void*)offsetof(NVertex3D, point));
	glEnableVertexAttribArray(0);

	m_ctVertices = count;
}

void NVertexBuffer::LoadElements(const uint32_t* pBuffer, uint32_t count)
{
	glGenBuffers(1, (GLuint*)&m_implBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, (GLuint)m_implBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * count, pBuffer, GL_STATIC_DRAW);

	m_ctIndices = count;
}

void NVertexBuffer::DrawArrays()
{
	glBindBuffer(GL_VERTEX_ARRAY, m_implBuffer);
	glBindVertexArray(m_implArray);
	glDrawArrays(GL_TRIANGLES, 0, m_ctVertices);
}

void NVertexBuffer::DrawElements()
{
}
