#include <cstdio>

#include "NimGL.h"

int main()
{
	NInit();

	NWindow window;
	window.m_bEscapeCloses = true;

	NTexture texture("../nimgl/Assets/Dog.jpg");

	while (window.DoEvents()) {
		window.Clear(NColor(0x232323FF));
		window.Display();
	}

	NEnd();

	return 0;
}
