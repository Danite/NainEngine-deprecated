#ifndef _RENDERER_H
#define _RENDERER_H

//C runtime header files
#ifndef _WINDOWS_h
	#include <Windows.h>
#endif

//Additional include files
#ifndef _VECTOR2D_H
	#include "Vector2D.h"
#endif
#ifndef _MATRIX2D_H
	#include "Matrix2D.h"
#endif
#ifndef _RECT2D_H
	#include "Rect2D.h"
#endif

#ifndef _COLOR_H
	#include "color.h"
#endif

//Forward Declaration
//class Image;

class Renderer
{
public:
	Renderer();
	~Renderer();

	//void* operator new(size_t size);
	//void operator delete(void* pdelete);

	void SetColor(const Color& c);
	void SetColor(float r, float g, float b, float a = 1.0f);

	void DrawRect(double left, double top, double width, double height, float lineWidth = 0.5f);
	void DrawRect(const Vector2D& lefttop, const Vector2D& rightbottom, float lineWidth = 0.5f);
	void DrawRect(const Rect2D& rect, float lineWidth = 0.5f);

	void FillRect(double left, double top, double width, double height);
	void FillRect(const Vector2D& lefttop, const Vector2D& rightbottom);
	void FillRect(const Rect2D& rect);
};

#endif
