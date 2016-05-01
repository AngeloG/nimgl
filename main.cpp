#include <cstdio>

#include "NimGL.h"

int main()
{
	NInit();

	NWindow window;
	window.m_bEscapeCloses = true;

	while (window.DoEvents()) {
		window.Clear(NColor(0x232323FF));
		window.Display();
	}

	return 0;
}
