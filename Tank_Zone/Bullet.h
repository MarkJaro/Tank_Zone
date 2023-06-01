#pragma once
#ifndef Bullet_H
#define Bullet_H

#define PI 3.14159265
#include <math.h>
#include <SDL.h>

#include "Particle.h"

class Bullet
{
protected:

	Particle body{};

	//const real drag = 0.85;
	const real drag = 0.9;

	/// <summary>
	/// 
	/// </summary>

	int w = 25;
	int h = 25;

	//int speed = 7;
	int startSpeed = 4;
	int speedLimit = 10;
	int direction;

	SDL_Rect rect = { 0, 0, 0, 0 };

	int maxLiveTime = 5; // in seconds
	unsigned startLiveTime;

	bool isAlive = true;


public:
	Bullet(int xOfPlayer, int yOfPlayer, int direction)
	{
		startLiveTime = SDL_GetTicks();
		int x = xOfPlayer + 50 * cos(direction * PI / 180);
		int y = yOfPlayer + 50 * sin(direction * PI / 180);
		this->direction = direction;

		body.position = Vector3(x, y, 0);

		float speedX = startSpeed * cos(this->direction * PI / 180);
		float speedY = startSpeed * sin(this->direction * PI / 180);

		body.acceleration = Vector3(speedX,
									speedY,
									 0);
	}

	void update()
	{
		unsigned currentLiveTime = (SDL_GetTicks() - startLiveTime) / 1000;
		//std::cout << "time - " << currentLiveTime << std::endl;

		if (currentLiveTime > maxLiveTime) { isAlive = false; }

		if (isAlive)
		{
			// change acceleration
			body.acceleration *= 0.5;
			body.acceleration.checkAccelerationLimit();

			// change velocity
			body.velocity = body.velocity + body.acceleration;

			// limit of speed if speed too big
			if (body.velocity.squareMagnitude() > speedLimit) { body.velocity *= 0.9; }


			// change position
			body.position = body.position + body.velocity;
		}
		

	}

	void push(Vector3 force)
	{
		body.acceleration = force;
	}

	bool alive() { return isAlive; }

	SDL_Rect* getRect()
	{
		rect.x = body.position.x;
		rect.y = body.position.y;

		rect.w = w;
		rect.h = h;

		return &rect;
	}

	~Bullet() {};

};
#endif