#pragma once

#include "NTexture.h"

class NSprite2D
{
public:
	NTexture m_texture;

public:
	NSprite2D(const char* filename);
	virtual ~NSprite2D();
};
