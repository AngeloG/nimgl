#include <cstdio>

#include "NimGL.h"

int main()
{
	NFile f("../nimgl/Assets/Quad.vtx.sha");
	NString shaderScript = f.ReadAll();

	printf("'%s'\n", (const char*)shaderScript);

	NInit();

	NWindow window;
	window.m_bEscapeCloses = true;

	NSprite2D texture("../nimgl/Assets/Dog.jpg");

	while (window.DoEvents()) {
		window.Clear(NColor(0x232323FF));
		window.Display();
	}

	NEnd();

	return 0;
}
