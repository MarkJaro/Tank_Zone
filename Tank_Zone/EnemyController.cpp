#include "EnemyController.h"

void EnemyController::takeAim()
{
	enemy->takeAim();
}

void EnemyController::shoot()
{
	enemy->shoot(bullets);
}

void EnemyController::updateEnemy()
{
	if (enemy->isAlive())
	{
		takeAim();
		shoot();

	}
}