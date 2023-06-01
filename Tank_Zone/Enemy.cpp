#include "Enemy.h"



double Enemy::findDirectionToPlayer()
{

	Vector3 playerPosition = target->getPosition();
	// tan = dx / dy
	double k = atan((body.position.x - playerPosition.x) / (body.position.y - playerPosition.y)) * 180 / PI;

	return k;
}

void Enemy::takeAim()
{
	int angle = findDirectionToPlayer();
	int rotate = this->rotate + 90;

	Vector3 playerPosition = target->getPosition();


	int measurementError = 5;

	int equation1;
	float equation2;

	if (playerPosition.y < body.position.y)
	{
		equation1 = angle - abs(rotate);
		equation2 = abs(rotate) - abs(angle);

		if (angle > 0)
		{
			if (equation1 > -measurementError) { rotateLeft(); } // rotateRight
			if (equation1 < measurementError) { rotateRight(); } // rotateLeft
			if (equation1 < measurementError && equation1 > -measurementError) { canShoot = true; }
		}

		if (angle < 0)
		{
			if (equation2 > -measurementError) { rotateLeft(); } // rotateRight
			if (equation2 < measurementError) { rotateRight(); } // rotateLeft
			if (equation2 < measurementError && equation2 > -measurementError) { canShoot = true; }
		}
	}

	if (playerPosition.y > body.position.y)
	{
		if (playerPosition.x < body.position.x)
		{
			angle = abs(angle) + 90;
		}

		if (playerPosition.x > body.position.x)
		{
			angle = 90 - abs(angle);
		}

		rotate = abs(rotate - 90);

		equation2 = rotate - angle;

		if (playerPosition.x > body.position.x)
		{
			if (equation2 > -measurementError) { rotateLeft(); } // rotateRight
			if (equation2 < measurementError) { rotateRight(); } // rotateLeft
			if (equation2 < measurementError && equation2 > -measurementError) { canShoot = true; }
		}

		if (playerPosition.x < body.position.x)
		{
			if (equation2 > -measurementError) { rotateLeft(); } // rotateRight
			if (equation2 < measurementError) { rotateRight(); } // rotateLeft
			if (equation2 < measurementError && equation2 > -measurementError) { canShoot = true; }
		}
	}
}


void Enemy::shoot(std::vector<Bullet*>* bullets)
{
	if (shootInPlayer)
	{
		if (canShoot)
		{
			Character::shoot(bullets);
		}
	}
}