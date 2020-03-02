#include "Canvas.h"
#include <stdlib.h>
#include <iostream>

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	this->figure = new char* [height];
	for (int i = 0; i < height; ++i) {

		this->figure[i] = new char[width];
		if (this->figure[i]) {
			for (int j = 0; j < width; ++j) {
				this->figure[i][j] = 32;
			}
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{

}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{

}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{

}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{

}
void Canvas::SetPoint(int x, int y, char ch)
{
	this->figure[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{

}
// shows what was printed
void Canvas::Print()
{
	if (this->figure) {
		for (int i = 0; i < height; ++i)
		{
			if (this->figure[i])
			{
				for (int j = 0; j < width; ++j)
				{
					std::cout << this->figure[i][j];
				}
			}
			std::cout << std::endl;
		}
	}
}
// clears the canvas
void Canvas::Clear()
{
	if (this->figure) {
		for (int i = 0; i < height; ++i)
		{
			if (this->figure[i])
			{
				for (int j = 0; j < width; ++j)
				{
					this->figure[i][j] = 32;
				}
			}
		}
	}
}