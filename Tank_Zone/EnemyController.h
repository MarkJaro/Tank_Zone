#pragma once
#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H

#include "Enemy.h"
#include "Bullet.h"

class EnemyController
{
public:
	Enemy* enemy;
	std::vector<Bullet*>* bullets{};

	EnemyController(Enemy* Enemy, std::vector<Bullet*>* Bullets) : enemy(Enemy), bullets(Bullets) { }

	void updateEnemy();

protected:
	void takeAim();
	void shoot();

};

#endif

