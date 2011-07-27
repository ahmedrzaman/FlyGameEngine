#ifndef _FLYENGINE_RECTANGLE_H
#define _FLYENGINE_RECTANGLE_H

struct Rectangle
{
	int X, Y, Width, Height;
	
	Rectangle() : X(0), Y(0), Width(0), Height(0) { }
	Rectangle(int x, int y, int width, int height) : X(x), Y(y), Width(width), Height(height) { }
};

#endif