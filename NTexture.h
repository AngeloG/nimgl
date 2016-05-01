#pragma once

#include "StdHP.h"

enum ETextureFormat
{
	TF_NONE,
	TF_RGB,
	TF_RGBA,
};

class NTexture
{
private:
	uint32_t m_implHandle;

public:
	ETextureFormat m_etfFormat;

public:
	NTexture();
	NTexture(int w, int h);
	NTexture(int w, int h, const ETextureFormat &fmt);
	NTexture(const char* filename);
	virtual ~NTexture();
};
