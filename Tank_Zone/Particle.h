#pragma once
#ifndef PARTICLE_H
#define PARTICLE_H
#include "Vector3.h"

class Particle
{
public:
	Vector3 position;
	Vector3 velocity;
	Vector3 acceleration;
};
#endif
