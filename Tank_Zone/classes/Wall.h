#ifndef Wall_H
#define Wall_H

#include <vector>

#include "Object.h"

class Wall : public Object
{
private:

	float x;
	float y;
	
	float sizeX;
	float sizeY;
	
	SDL_Rect srcrect; // Размер текстуры
	SDL_Rect dstrect; // Размер
	
	
	
public:
	
	Wall() {}
	
	Wall(int x, int y, int sX, int sY)
	{
		this->x = x;
		this->y = y;
		this->sizeX = sX;
		this->sizeY = sY;
		
		srcrect.x = x; //300;
		srcrect.y = y; //300;
		srcrect.w = 200;
		srcrect.h = 20;
		
		dstrect.x = 640/4;
		dstrect.y = 480/4;
		dstrect.w = 75;
		dstrect.h = 75;
	}
	
	float getX() { return x; }
	float getY() { return y; }
	
	SDL_Rect* getSrc() { return &srcrect; }
	SDL_Rect* getDst() { return &dstrect; }
	
};
#endif