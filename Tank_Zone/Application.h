#pragma once

#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>
#include "Program.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Wall.h"
#include "Settings.h"
#include "PlayerController.h"
#include "EnemyController.h"
#include "CollisionController.h"
class Application : public Program
{
protected:

	Player player{500, 300};
	Enemy enemy{ 700, 400, &player, shootInPlayer };
	std::vector<Bullet*> bullets{};
	std::vector<Wall*> walls{};

	bool shootInPlayer = true;

	PlayerController playerController{ &player, &bullets, &walls };
	EnemyController enemyController{ &enemy, &bullets };
	CollisionController collisionController{ &player, &enemy, &bullets, &walls };
	
	// textures
	SDL_Texture* playerTexture;
	SDL_Texture* enemyTexture;
	SDL_Texture* bulletTexture;
	SDL_Texture* wallTexture;
	SDL_Texture* debugTexture;

public:
	Application(int w = 640 * 2, int h = 640, int fps = 60) : Program(w, h, fps) {};
	
	void run();

	void handleEvents() override;
	void process() override;
	void removingDeadObjects();
	void render() override;

	void clearScreen();
	void drawObjects();
	void updateScreen();
};

#endif