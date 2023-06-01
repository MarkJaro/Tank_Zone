#pragma once

#ifndef PHYSICSCONTROLLER_H
#define PHYSICSCONTROLLER_H

#define PI 3.14159265

#include <math.h>
#include <SDL.h>
#include <vector>
#include "Player.h"
#include "Bullet.h"
#include "Wall.h"
#include "Vector3.h"

class CollisionController
{
protected:
	Player* player;
	std::vector<Bullet*>* bullets;
	std::vector<Wall*>* walls;

public:
	CollisionController(Player* player, std::vector<Bullet*>* bullets, std::vector<Wall*>* walls) : player(player), bullets(bullets), walls(walls) {}

	void checkPlayerWithWallCollision();
	void checkPlayerWithBulletCollision();
	void checkBulletWithWallCollision();

	bool areColliding(SDL_Rect* obj1, SDL_Rect* obj2);

};

#endif