#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#define PI 3.14159265
#include "Character.h"

class Player : public Character
{
public:
	Player(int x, int y) : Character(x, y) {}

	Vector3 getPosition();
};

#endif