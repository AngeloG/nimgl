#include "StdH.h"
#include "NWindowContext.h"
#include "NimGL_internal.h"

NWindowContext::NWindowContext(void* pWindow)
{
	if (g_pContext == nullptr) {
		return;
	}

	m_implContext = (void*)SDL_GL_CreateContext((SDL_Window*)pWindow);

	const GLubyte* szVersion = glGetString(GL_VERSION);
	const GLubyte* szVendor = glGetString(GL_VENDOR);
	const GLubyte* szRenderer = glGetString(GL_RENDERER);

	printf("OpenGL version: %s\n", szVersion);
	printf("OpenGL vendor: %s\n", szVendor);
	printf("OpenGL renderer: %s\n", szRenderer);

	if (!g_pContext->m_bGlewInitialized) {
		glewExperimental = true;
		glewInit();
		glGetError(); // first error might not be GL_NO_ERROR on some machines, so ignore thi
	}

	const NVertex2D arrQuad[] = {
		{{ 0, 0 }}, {{ 1, 0 }}, {{ 1, 1 }},
		{{ 1, 1 }}, {{ 0, 1 }}, {{ 0, 0 }},
	};
	m_vboQuad.LoadBuffer(arrQuad, 6);
}

NWindowContext::~NWindowContext()
{
	if (m_implContext != nullptr) {
		SDL_GL_DeleteContext((SDL_GLContext)m_implContext);
		m_implContext = nullptr;
	}
}
