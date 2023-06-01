#pragma once

#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#define PI 3.14159265
#include <math.h>

#include <vector>
#include <math.h>
#include "Player.h"
#include "Bullet.h"
#include "Wall.h"
#include "Vector3.h"

class PlayerController
{
protected:
	Player* player;
	std::vector<Bullet*>* bullets;
	std::vector<Wall*>* walls;

public:
	PlayerController(Player* player, std::vector<Bullet*>* bullets, std::vector<Wall*>* walls) : player(player), bullets(bullets), walls(walls) {}

	void moveForward();
	void moveBackward();

	void rotateRight();
	void rotateLeft();

	void shoot();

	void update();


};

#endif