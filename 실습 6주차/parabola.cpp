#include <iostream>
#include <windows.h>
#include "Parabola.h"
using namespace std;

void MyCircle::initCircle(Point position, Point velocity, Point acceleration, float radius)
{
	pos = position;
	vel = velocity;
	rad = radius;
	acc = acceleration;
}

void MyCircle::drawCircle(HDC hdc) {

	Point p0;
	Point p1;

	p0.x = pos.x - rad; //왼쪽 위에 있는 점
	p0.y = pos.y - rad;

	p1.x = pos.x + rad; //오른쪽 아래에 있는 점
	p1.y = pos.y + rad;

	Ellipse(hdc, p0.x, p0.y, p1.x, p1.y);
}