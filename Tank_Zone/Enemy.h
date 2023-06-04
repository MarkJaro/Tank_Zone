#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#define PI 3.14159265

#include "math.h"

#include "Character.h"
#include "Player.h"

class Enemy : public Character
{
protected:
	Player* target;

	bool canShoot = false;
	bool shootInPlayer = true;

public:
	Enemy(int x, int y, Player* player, bool shootInPlayer = true) : Character(x, y), target(player)
	{
		this->shootInPlayer = shootInPlayer;

		float newCooldown = 2.0;
		setCooldown(newCooldown);
		
	}

	void takeAim();
	void shoot(std::vector<Bullet*>* bullets) override;

protected:
	double findDirectionToPlayer();

};

#endif

