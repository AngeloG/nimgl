# nimgl

## What the fuck is this?

My attempt at a simple OpenGL rendering framework. It's probably shit. Either way I'm
publishing it because maybe someone can tell me why it's shit. Or actually just because
I reached the limit of my Github private repo subscription. Oh well.

Here's to learning.

![](https://i.imgur.com/vG1hRGJ.jpg)

## Current state

```
int main()
{
	NInit();
	
	NWindow window;
	
	while (window.DoEvents()) {
		window.Clear();
		window.Display();
	}
	
	return 0;
}
```
