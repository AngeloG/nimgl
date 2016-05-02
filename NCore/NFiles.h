#pragma once

#include "NString.h"

class NFile
{
private:
	void* m_implHandle;
	bool m_atEOF;

public:
	NFile(const char* filename, const char* mode = "rb");
	virtual ~NFile();

	virtual NString ReadLine();
	virtual NString ReadAll();
};

bool nfilExists(const char* filename);
