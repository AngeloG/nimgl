#include "StdH.h"
#include "NimGL.h"
#include "NimGL_internal.h"

NContext* g_pContext = nullptr;

void NInit()
{
	if (g_pContext != nullptr) {
		return;
	}
	g_pContext = new NContext;
}

void NEnd()
{
	if (g_pContext == nullptr) {
		return;
	}
	delete g_pContext;
	g_pContext = nullptr;
}

glm::vec4 NColor(uint32_t _32bpp)
{
	uint8_t r = (_32bpp & 0xFF000000) >> 24;
	uint8_t g = (_32bpp & 0x00FF0000) >> 16;
	uint8_t b = (_32bpp & 0x0000FF00) >> 8;
	uint8_t a = (_32bpp & 0x000000FF);
	return NColor(r, g, b, a);
}

glm::vec4 NColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return NColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
}

glm::vec4 NColor(float r, float g, float b, float a)
{
	return glm::vec4(r, g, b, a);
}
