#include "Application.h"


void Application::run()
{
	std::string playerTexturePath = "img/tank.png";
	playerTexture = Program::loadTexture(playerTexturePath);

	std::string EnemyTexturePath = "img/enemy.png";
	enemyTexture = Program::loadTexture(EnemyTexturePath);

	std::string bulletTexturePath = "img/bullet.png";
	bulletTexture = Program::loadTexture(bulletTexturePath);

	std::string wallTexturePath = "img/wall1.png";
	wallTexture = Program::loadTexture(wallTexturePath);

	std::string debugTexturePath = "img/to_test.png";
	debugTexture = Program::loadTexture(debugTexturePath);


	// Map

	float impulse = 0.1;
	Vector3 wallDirectionUp(0, -impulse, 0);
	Vector3 wallDirectionDown(0, impulse, 0);
	Vector3 wallDirectionRight(impulse, 0, 0);
	Vector3 wallDirectionLeft(-impulse, 0, 0);

	walls.push_back(new Wall(300, 600, 600, 10, wallDirectionUp));
	walls.push_back(new Wall(300,  10, 600, 10, wallDirectionDown));
	walls.push_back(new Wall(300,  10, 10, 600, wallDirectionRight));
	walls.push_back(new Wall(890,  10, 10, 600, wallDirectionLeft));

	//player = new Player(500, 300);


	Program::run();
}

void Application::handleEvents()
{
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			running = false;
		}

		// key press
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case up:   
				playerController.moveForward();
				break;
			case down:
				playerController.moveBackward();
				break;
			case right:
				playerController.rotateRight();
				break;
			case left:
				playerController.rotateLeft();
				break;
			case shoot:
				playerController.shoot();
				break;
			}
		}
	}

}

void Application::process()
{
	playerController.update();
	
	enemyController.updateEnemy();

	for (Bullet* bullet : bullets)
	{
		bullet->update();
	}

	collisionController.update();

	for(int i = 0; i < bullets.size(); i++)
	{
		if ( !bullets[i]->alive() )
		{
			bullets.erase(bullets.begin() + i);
		}
	}

}

void Application::render()
{
	clearScreen();
	drawObjects();
	updateScreen();
}


void Application::clearScreen()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
	SDL_RenderClear(renderer);
}

void Application::drawObjects()
{
	//draw bullets
	for (Bullet* bullet : bullets)
	{
		if (bullet->alive())
		{
			SDL_RenderCopyEx(renderer, bulletTexture, NULL, bullet->getRect(), 0, NULL, SDL_FLIP_HORIZONTAL);
		}
	}

	//draw walls
	for (Wall* wall : walls)
	{
		SDL_RenderCopyEx(renderer, wallTexture, NULL, wall->getRect(), 0, NULL, SDL_FLIP_HORIZONTAL);
	}

	// draw player
	if (player.isAlive())
	{
		SDL_RenderCopyEx(renderer, playerTexture, NULL, player.getRect(), player.getDirection() + 90, NULL, SDL_FLIP_HORIZONTAL);
	}

	// draw enemy
	if (enemy.isAlive())
	{
		SDL_RenderCopyEx(renderer, enemyTexture, NULL, enemy.getRect(), enemy.getDirection() + 90, NULL, SDL_FLIP_HORIZONTAL);
	}

}

void Application::updateScreen()
{
	SDL_RenderPresent(renderer);
}


