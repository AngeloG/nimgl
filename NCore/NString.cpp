#include "StdH.h"
#include "NString.h"

char* NString::ms_empty = (char*)"";

NString::NString()
{
	m_buffer = ms_empty;
	m_bufferSize = 0;
	m_bufferLength = 0;
}

NString::NString(const char* str)
	: NString()
{
	CopyString(str);
}

NString::NString(const NString &copy)
	: NString((const char*)copy)
{
}

NString::~NString()
{
	if (m_buffer != ms_empty) {
		free(m_buffer);
	}
}

NString::operator const char*() { return m_buffer; }
NString::operator const char*() const { return m_buffer; }

NString &NString::operator +=(const char* str)
{
	int len = strlen(str);
	EnsureBuffer(m_bufferLength + len + 1);

	memcpy(m_buffer + m_bufferLength, str, len);
	m_bufferLength += len;
	m_buffer[m_bufferLength] = '\0';

	return *this;
}

void NString::EnsureBuffer(int length)
{
	if (length <= m_bufferSize) {
		return;
	}

	if (m_buffer != ms_empty) {
		m_buffer = (char*)realloc(m_buffer, length);
	} else {
		m_buffer = (char*)malloc(length);
	}
	m_bufferSize = length;
}

void NString::CopyString(const char* str)
{
	m_bufferLength = strlen(str);

	EnsureBuffer(m_bufferLength + 1);

	memcpy(m_buffer, str, m_bufferLength);
	m_buffer[m_bufferLength] = '\0';
}

NString operator+(const NString &a, const char* b)
{
	return NString(a) += b;
}
