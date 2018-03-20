#include <windows.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>


//8分法实现画圆
void Circle_Midpoint(int x, int y, int r, int color)
{
	int tx = 0, ty = r, d = 1 - r;
	while (tx <= ty)
	{
		putpixel(x + tx, y + ty, color);
		putpixel(x + tx, y - ty, color);
		putpixel(x - tx, y + ty, color);
		putpixel(x - tx, y - ty, color);
		putpixel(x + ty, y + tx, color);