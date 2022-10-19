#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Point
{
public:
	float x;
	float y;
};

class MyCircle
{
public:

	Point pos;
	Point vel;
	Point acc;
	float rad;
	
	void initCircle(Point position, Point velocity, Point acceleration, float radius);
	void drawCircle(HDC hdc);

};