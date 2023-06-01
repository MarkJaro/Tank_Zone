#ifndef Bullet_H
#define Bullet_H

#include "Object.h"
#include <math.h>

#define PI 3.14159265

class Bullet : public Object
{
private:
	float speed = 1.5;	
	float degrees;
	bool move = true;
	
	float x = 100;
	float y = 100;
	
	int w = 25;
	int h = 25;
	
	SDL_Rect heatbox = { x, y, w, h };
public:
	
	/*
	
	Dot::Dot( int x, int y )
	{
		
	}
	
	*/
	
	
	Bullet(float d, float x, float y) // x,y of tank
	{
		degrees = d;
		this->x = x + 20 * cos(degrees*PI/180);
		this->y = y + 20 * sin(degrees*PI/180);
	}
	
	void stop()
	{
		move = false;
	}
	
	void run(float d = 0)
	{
		degrees = d;
		move = true;
	}
	
	void update()
	{
		if(move)
		{
			x += speed * cos(degrees*PI/180); 
			y += speed * sin(degrees*PI/180);
		}
		
	}
	
	
	
	SDL_Rect* GetRect()
	{
		heatbox.x = x;
		heatbox.y = y;
		
		heatbox.w = w;
		heatbox.h = h;
		
		return &heatbox;
	}
	
};
#endif