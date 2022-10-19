#include <iostream>
#include <windows.h>
#include "Parabola.h"
using namespace std;

int main()
{
	HDC hdc = GetWindowDC(GetForegroundWindow());
	
	MyCircle circle; //circle1
	
	Point position;
	position.x = 20;
	position.y = 200;
	
	Point velocity;
	velocity.x = 50;
	velocity.y = 50;
	
	Point acceleration;
	acceleration.x = 0;
	acceleration.y = -9.8;
	float radius = 10;
	
	circle.initCircle(position, velocity, acceleration, radius); 
	circle.drawCircle(hdc);
	
	
	MyCircle circle2; //circle2
	
	position.x = 20;
	position.y = 400;
	
	velocity.x = 20;
	velocity.y = 20;
	
	acceleration.x = 0;
	acceleration.y = -9.8;
	
	radius = 10;
	
	circle2.initCircle(position, velocity, acceleration, radius);
	circle2.drawCircle(hdc);

	for (float dt = 0; dt < 1; dt = dt + 0.001) {
		circle.pos.x += circle.vel.x * dt; //for circle 1
		circle.pos.y += circle.vel.y * dt;

		//cout << circle.pos.x << " " << circle.pos.y << endl;
		circle.vel.x += circle.acc.x * dt;
		circle.vel.y += circle.acc.y * dt;

		circle2.pos.x += circle2.vel.x * dt; //for circle 2
		circle2.pos.y += circle2.vel.y * dt;

		circle2.vel.x += circle2.acc.x * dt;
		circle2.vel.y += circle2.acc.y * dt;

		circle.drawCircle(hdc); //circle 1
		circle2.drawCircle(hdc); //circle 2
		Sleep(20);
	}
}