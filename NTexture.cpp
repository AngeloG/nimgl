#include "StdH.h"
#include "NTexture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

NTexture::NTexture()
{
	glGenTextures(1, &m_implHandle);
	m_etfFormat = TF_NONE;
}

NTexture::NTexture(int w, int h)
	: NTexture(w, h, TF_RGBA)
{
}

NTexture::NTexture(int w, int h, const ETextureFormat &fmt)
	: NTexture()
{
	m_etfFormat = fmt;

	GLint iGLFormat;
	switch (fmt) {
	case TF_RGB: iGLFormat = GL_RGB; break;
	case TF_RGBA: iGLFormat = GL_RGBA; break;
	default: printf("Unknown texture format: %x\n", (int)fmt); break;
	}

	glBindTexture(GL_TEXTURE_2D, m_implHandle);
	glTexImage2D(GL_TEXTURE_2D, 0, iGLFormat, w, h, 0, iGLFormat, GL_UNSIGNED_BYTE, nullptr);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

NTexture::NTexture(const char* filename)
	: NTexture()
{
	int w, h, comp;
	unsigned char* buffer = stbi_load(filename, &w, &h, &comp, 4);

	GLint iGLFormat;
	switch (comp) {
	case 3:
		iGLFormat = GL_RGB;
		m_etfFormat = TF_RGB;
		break;

	case 4:
		iGLFormat = GL_RGBA;
		m_etfFormat = TF_RGBA;
		break;

	default: printf("Unsupported texture type with %d components: '%s'\n", comp, filename); break;
	}

	glBindTexture(GL_TEXTURE_2D, m_implHandle);
	glTexImage2D(GL_TEXTURE_2D, 0, iGLFormat, w, h, 0, iGLFormat, GL_UNSIGNED_BYTE, buffer);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	stbi_image_free(buffer);
}

NTexture::~NTexture()
{
	glDeleteTextures(1, &m_implHandle);
}
