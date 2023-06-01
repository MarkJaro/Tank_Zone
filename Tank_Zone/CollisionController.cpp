#include "CollisionController.h"


void CollisionController::checkPlayerWithWallCollision()
{
	for (Wall* wall : *walls)
	{
		bool PlayerCollidingWithWall = areColliding(player->getHeatbox(), wall->getRect());
		if (PlayerCollidingWithWall)
		{
			SDL_Rect wallRect = *wall->getRect();

			//Vector3 w = { (float)(wallRect.x + wallRect.w / 2), (float)(wallRect.y + wallRect.w / 2), 0 };
			//Vector3 position = { player->getX(), player->getY(), 0 };
			//Vector3 force = position - w;
			//Vector3 g = { 0, -0.1, 0 };
			Vector3 force = wall->getDirection();
			force.normilize();
			player->push(force);
		}
	}
}
void CollisionController::checkPlayerWithBulletCollision()
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

void CollisionController::checkBulletWithWallCollision()
{
	
	for (Bullet* bullet : *bullets)
	{
		for (Wall* wall : *walls)
		{
			bool BulletCollidingWithWall = areColliding(bullet->getRect(), wall->getRect());
			if (BulletCollidingWithWall)
			{
				//bullet->changeDirection(wall->getId());
				//Vector3 force = position - w;
				//Vector3 g = { 0, -0.1, 0 };
				Vector3 force = wall->getDirection();
				force.normilize();
				force.normilize();
				bullet->push(force);
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