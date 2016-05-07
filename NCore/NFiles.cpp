#include "StdH.h"
#include "NFiles.h"

NFile::NFile(const char* filename, const char* mode)
{
	m_implHandle = fopen(filename, mode);
	m_atEOF = false;
}

NFile::~NFile()
{
	if (m_implHandle != nullptr) {
		fclose((FILE*)m_implHandle);
	}
}

NString NFile::ReadLine()
{
	if (m_implHandle == nullptr || m_atEOF) {
		return "";
	}
	char buffer[512];
	if (fgets(buffer, 512, (FILE*)m_implHandle) == nullptr) {
		m_atEOF = true;
	} else {
		buffer[strlen(buffer)-1] = '\0';
	}
	return NString(buffer);
}

NString NFile::ReadAll()
{
	NString ret;
	char buffer[512];
	while (!m_atEOF) {
		int ctRead = fread(buffer, 1, 511, (FILE*)m_implHandle);
		if (ctRead < 511) {
			m_atEOF = true;
		}
		buffer[ctRead] = '\0';
		ret += buffer;
	}
	return ret;
}
