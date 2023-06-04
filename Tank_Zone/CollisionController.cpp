#include "CollisionController.h"

void CollisionController::update()
{
	checkPlayerWithWallCollision();
	checkEnemyWithBulletCollision();
	checkPlayerWithBulletCollision();
	checkBulletWithWallCollision();
}

void CollisionController::checkPlayerWithWallCollision()
{
	if (player->isAlive())
	{
		for (Wall* wall : *walls)
		{
			bool PlayerCollidingWithWall = areColliding(player->getHeatbox(), wall->getRect());
			if (PlayerCollidingWithWall)
			{
				SDL_Rect wallRect = *wall->getRect();
				Vector3 force = wall->getDirection();
				force.normilize();
				player->push(force);
			}
		}
	}
}
void CollisionController::checkPlayerWithBulletCollision()
{
	if (player->isAlive())
	{
		for (Bullet* bullet : *bullets)
		{
			bool PlayerCollidingWithBullet = areColliding(player->getHeatbox(), bullet->getRect());
			if (PlayerCollidingWithBullet)
			{
				player->kill();
			}
		}
	}
}

void CollisionController::checkBulletWithWallCollision()
{
	
	for (Bullet* bullet : *bullets)
	{
		for (Wall* wall : *walls)
		{
			bool BulletCollidingWithWall = areColliding(bullet->getRect(), wall->getRect());
			if (BulletCollidingWithWall)
			{
				Vector3 force = wall->getDirection();
				force.normilize();
				force.normilize();
				bullet->push(force);
			}
		}
	}	
}

void CollisionController::checkEnemyWithBulletCollision()
{
	if (enemy->isAlive())
	{
		for (Bullet* bullet : *bullets)
		{
			bool PlayerCollidingWithBullet = areColliding(enemy->getHeatbox(), bullet->getRect());
			if (PlayerCollidingWithBullet)
			{
				enemy->kill();
			}
		}
	}
}

bool CollisionController::areColliding(SDL_Rect* obj1, SDL_Rect* obj2)
{
	if (obj1->y < obj2->y + obj2->h &&
		obj1->y + obj1->h > obj2->y &&
		obj1->x < obj2->x + obj2->w &&
		obj1->x + obj1->w > obj2->x)
	{
		return true;
	}

	return false;
}