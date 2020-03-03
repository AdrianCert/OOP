#include "Canvas.h"
#include <stdlib.h>
#include <iostream>

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	if (width > 0 && height > 0)
	{
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
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (ray * ray == (x - i) * (x - i) + (y - j) * (y - j))
			{
				this->figure[i][j] = ch;
			}
		}
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (ray * ray >= (x - i) * (x - i) + (y - j) * (y - j))
			{
				this->figure[i][j] = ch;
			}
		}
	}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		this->figure[top][i] = ch;
		this->figure[bottom][i] = ch;
	}
	for (int i = top; i <= bottom; i++)
	{
		this->figure[i][left] = ch;
		this->figure[i][right] = ch;
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int x = left; x <= right; x++)
	{
		for (int y = top; y <= bottom; y++)
		{
			this->figure[x][y] = ch;
		}
	}
}
void Canvas::SetPoint(int x, int y, char ch)
{
	this->figure[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int m_new = 2 * (y2 - y1);
	int slope_error_new = m_new - (x2 - x1);
	for (int x = x1, y = y1; x <= x2; x++)
	{
		this->figure[x][y] = ch;

		// Add slope to increment angle formed 
		slope_error_new += m_new;

		// Slope error reached limit, time to 
		// increment y and update slope error. 
		if (slope_error_new >= 0)
		{
			y++;
			slope_error_new -= 2 * (x2 - x1);
		}
	}
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