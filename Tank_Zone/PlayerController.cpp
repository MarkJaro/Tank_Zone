#include "PlayerController.h"

void PlayerController::moveForward()
{
	if (player->isAlive())
	{
		Vector3 force( cos((float)( player->getDirection() * PI / 180)),
						sin((float)( player->getDirection() * PI / 180)),
						0);
		force.normilize();
		player->push(force);
	}
	
}

void PlayerController::moveBackward()
{
	if (player->isAlive())
	{
		Vector3 force( -cos((float)(player->getDirection() * PI / 180)),
						-sin((float)(player->getDirection() * PI / 180)),
						0);
		force.normilize();
		player->push(force);
	}
	
}

void PlayerController::rotateRight()
{
	if (player->isAlive())
	{
		player->rotateRight();
	}
}
void PlayerController::rotateLeft()
{
	if (player->isAlive())
	{
		player->rotateLeft();
	}
}
void PlayerController::shoot()
{
	if (player->isAlive())
	{
		player->shoot(bullets);
	}
}

void PlayerController::update()
{
	if (player->isAlive())
	{
		player->update();
	}
}
