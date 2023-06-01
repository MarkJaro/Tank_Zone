#pragma once

#ifndef WALL_H
#define WALL_H

typedef float real;

#include <SDL.h>
#include "Counter.h"

class Wall
{
protected:
	int x;
	int y;
	int w;
	int h;

	int id;

	Vector3 direction;

	SDL_Rect rect = { x, y, w, h };
public:
	Wall(int x, int y, int w, int h, Vector3 dir) : x(x), y(y), w(w), h(h), direction(dir) { id = Counter::getId(); };

	int getId() { return id; };

	Vector3 getDirection()
	{
		return direction;
	}

	SDL_Rect* getRect()
	{
		rect.x = x;
		rect.y = y;

		rect.w = w;
		rect.h = h;

		return &rect;
	}
	
};

#endif