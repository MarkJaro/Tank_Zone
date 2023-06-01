#include "Character.h"

Character::Character(int x, int y)
{
	body.position.x = (real)x;
	body.position.y = (real)y;
	body.position.z = 0;
}

float Character::getDirection() { return rotate; }

void Character::push(Vector3 force)
{
	body.acceleration += force;
}

void Character::calculateMovement()
{
	// change acceleration
	body.acceleration *= 0.89;
	body.acceleration.checkAccelerationLimit();

	// change velocity
	body.velocity = body.velocity * drag + body.acceleration;

	// change position
	body.position = body.position + body.velocity;
}

void Character::calculateHeatbox()
{
	//w
	float wR = (hypotenuse * cos((rotate + startDegR) * PI / 180)); // 
	float wL = (hypotenuse * cos((rotate + startDegL) * PI / 180)); // 

	wR = wR < 0 ? -wR : wR;
	wL = wL < 0 ? -wL : wL;

	width = wR > wL ? wR : wL;


	// h

	float hR = (hypotenuse * sin((rotate + startDegR) * PI / 180)); // 
	float hL = (hypotenuse * sin((rotate + startDegL) * PI / 180)); // 

	hR = hR < 0 ? -hR : hR;
	hL = hL < 0 ? -hL : hL;

	height = hR > hL ? hR : hL;
}

void Character::update()
{
	calculateMovement();
	calculateHeatbox();
}

void Character::rotateRight()
{
	rotate += rotateSpeed;
	if (rotate > 180) { rotate = -180; }
}

void Character::rotateLeft()
{
	rotate -= rotateSpeed;
	if (rotate < -180) { rotate = 180; }
}


SDL_Rect* Character::getRect()
{
	rect.x = body.position.x;
	rect.y = body.position.y;

	return &rect;
}

SDL_Rect* Character::getHeatbox()
{
	heatbox.x = body.position.x + rect.w / 2 - width / 2;
	heatbox.y = (body.position.y + rect.h / 2 - height / 2);

	heatbox.w = width;
	heatbox.h = height;

	return &heatbox;
}

bool Character::isAlive() { return alive; }

void Character::kill() { alive = false; }

void Character::shoot(std::vector<Bullet*>* bullets)
{
	// first shot
	if (startCooldown == -1) { shot(bullets); }
	//else
	unsigned currentCooldown = (SDL_GetTicks() - startCooldown) / 1000;

	bool haveAmmo = ammoLimit > bullets->size();
	bool hasNotCooldown = currentCooldown > shootCooldown;

	if (haveAmmo && hasNotCooldown) { shot(bullets); }
}

void Character::shot(std::vector<Bullet*>* bullets)
{
	bullets->push_back(new Bullet(body.position.x, body.position.y, rotate));
	startCooldown = SDL_GetTicks();
}