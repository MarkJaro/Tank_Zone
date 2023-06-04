#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#define PI 3.14159265

#include <SDL.h>
#include <vector>
#include "Bullet.h"
#include "Particle.h"

class Character
{
protected:
	Particle body{};

	real width = 25;
	real height = 35;

	int playerId;

	// rotate in degrees
	float rotate = -90;

	float rotateSpeed = 5.0;

	// const real drag = 0.85;
	const real drag = 0.1;


	int ammoLimit = 5; // how many bullets can be on the screen in one moment
	bool alive = true;

	//time
	float shootCooldown = 0.6; // in seconds
	unsigned startCooldown = -1;


	// variables for heatbox calculation

	float hypotenuse = sqrt(width * width + height * height); // Pifagor
	// only for rotate = -90
	float startDegR = 90 - 54.462322; // tan-1(h/w)
	float startDegL = 90 + 54.462322; // tan+1(h/w)

	// end of heatbox calculation variables


	SDL_Rect rect = { 0,
					  0,
					  (int)width,
					  (int)height };

	SDL_Rect heatbox = { 0,0,0,0 };





public:
	Character(int x = 100, int y = 100);

	float getDirection();

	SDL_Rect* getRect();
	SDL_Rect* getHeatbox();

	void push(Vector3 force);
	virtual void update();
	void calculateMovement();
	void calculateHeatbox();

	void rotateRight();
	void rotateLeft();

	bool isAlive();
	void kill();

	virtual void shoot(std::vector<Bullet*>* bullets);
protected:
	void shot(std::vector<Bullet*>* bullets);
	void setCooldown(float cooldown);
};

#endif