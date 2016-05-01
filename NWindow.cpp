#include "StdH.h"
#include "NWindow.h"

NWindow::NWindow()
	: NWindow("NimGL", 800, 600)
{
}

NWindow::NWindow(const char* title)
	: NWindow(title, 800, 600)
{
}

NWindow::NWindow(const char* title, int w, int h)
{
	m_implWindow = (void*)SDL_CreateWindow("NimGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_OPENGL);
	m_implContext = (void*)SDL_GL_CreateContext((SDL_Window*)m_implWindow);

	m_bEscapeCloses = false;
}

NWindow::~NWindow()
{
	Destroy();
}

bool NWindow::DoEvents()
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev)) {
		switch (ev.type) {
		case SDL_QUIT:
			Destroy();
			return false;

		case SDL_KEYDOWN:
			if (ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE && m_bEscapeCloses) {
				Destroy();
				return false;
			}
			break;
		}
	}
	return true;
}

void NWindow::Clear()
{
	Clear(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
}

void NWindow::Clear(const glm::vec4 &col)
{
	glClearColor(col.r, col.g, col.b, col.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void NWindow::Display()
{
	SDL_GL_SwapWindow((SDL_Window*)m_implWindow);

	GLenum err = glGetError();
	if (err != GL_NO_ERROR) {
		printf("OpenGL error: %x\n", err);
	}
}

void NWindow::Destroy()
{
	if (m_implContext != nullptr) {
		SDL_GL_DeleteContext((SDL_GLContext)m_implContext);
		m_implContext = nullptr;
	}
	if (m_implWindow != nullptr) {
		SDL_DestroyWindow((SDL_Window*)m_implWindow);
		m_implWindow = nullptr;
	}
}
