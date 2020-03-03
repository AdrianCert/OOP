#ifndef _CANVAS_H_
#define _CANVAS_H_

class Canvas
{
	int width = 0;
	int height = 0;
	char** figure = 0;
public:
	Canvas() = delete;
	Canvas(int width, int height);
	void DrawCircle(int x, int y, int ray, char ch);
	void FillCircle(int x, int y, int ray, char ch);
	void DrawRect(int left, int top, int right, int bottom, char ch);
	void FillRect(int left, int top, int right, int bottom, char ch);
	void SetPoint(int x, int y, char ch);
	void DrawLine(int x1, int y1, int x2, int y2, char ch);
	void Print(); // shows what was printed
	void Clear(); // clears the canvas
};

#endif // !_CANVAS_H_