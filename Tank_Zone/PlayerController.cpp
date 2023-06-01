#include "PlayerController.h"

void PlayerController::moveForward()
{
	Vector3 force( cos((float)( player->getDirection() * PI / 180)),
				   sin((float)( player->getDirection() * PI / 180)),
				   0);
	force.normilize();
	player->push(force);
}

void PlayerController::moveBackward()
{
	Vector3 force( -cos((float)(player->getDirection() * PI / 180)),
				   -sin((float)(player->getDirection() * PI / 180)),
				   0);
	force.normilize();
	player->push(force);
}

void PlayerController::rotateRight()
{
	player->rotateRight();
}

void PlayerController::rotateLeft()
{
	player->rotateLeft();
}

void PlayerController::shoot()
{
	player->shoot(bullets);
}

void PlayerController::update()
{
	player->update();
}
