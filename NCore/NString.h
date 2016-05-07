#pragma once

#include "StdH.h"

class NString
{
private:
	static char* ms_empty;

	char* m_buffer;
	int m_bufferSize;
	int m_bufferLength;

public:
	NString();
	NString(const char* str);
	NString(const NString &copy);
	~NString();

	operator const char*();
	operator const char*() const;

	NString &operator +=(const char* str);

private:
	void EnsureBuffer(int length);
	void CopyString(const char* str);
};

NString operator+(const NString &a, const char* b);
