#pragma once

#ifndef PHYSICSCONTROLLER_H
#define PHYSICSCONTROLLER_H

#define PI 3.14159265

#include <math.h>
#include <SDL.h>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Wall.h"
#include "Vector3.h"

class CollisionController
{
protected:
	Player* player;
	Enemy* enemy;
	std::vector<Bullet*>* bullets;
	std::vector<Wall*>* walls;

public:
	CollisionController(Player* player, Enemy* enemy, std::vector<Bullet*>* bullets, std::vector<Wall*>* walls) : player(player), enemy(enemy) ,bullets(bullets), walls(walls) {}

	void update();

protected:
	void checkPlayerWithWallCollision();
	void checkPlayerWithBulletCollision();
	void checkBulletWithWallCollision();
	void checkEnemyWithBulletCollision();

	bool areColliding(SDL_Rect* obj1, SDL_Rect* obj2);

};

#endif