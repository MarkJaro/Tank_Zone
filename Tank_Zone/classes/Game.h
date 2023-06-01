#ifndef Game_H
#define Game_H

//Using SDL and standard IO
//#include "SDL.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

//#include "stdio.h"
#include <iostream>
#include <vector>

#include "Player.h"
#include "Bullet.h"
#include "Wall.h"
#include "Object.h"


class Game
{
private:
	
	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	enum KeyPressSurfaces
	{
		KEY_PRESS_SURFACE_DEFAULT,
		KEY_PRESS_SURFACE_UP,
		KEY_PRESS_SURFACE_DOWN,
		KEY_PRESS_SURFACE_LEFT,
		KEY_PRESS_SURFACE_RIGHT,
		KEY_PRESS_SURFACE_TOTAL
	};
	
	SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];


	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Renderer* gRenderer = NULL;
	
	// Objects
	std::vector<Player*> players;
	std::vector<Bullet*> bullets;
	std::vector<Wall*> walls;
	Player tank;

	//Current displayed texture
	SDL_Texture* gTexture = NULL;
	SDL_Texture* bulletTestImg = NULL;
	
	
	unsigned target_fps = 60;
	unsigned frame_delay = 16;
	unsigned time_frame_start = 0;
	unsigned time_frame_end = 0;
	unsigned time_next_frame = 0;
	unsigned sleep_duration = 0;
	
	
	// init
	SDL_Event e;
	bool quit = false;
	
	
	
	
	SDL_Texture* loadTexture( std::string path )
	{
		SDL_Texture* newTexture = NULL;

		SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
		if( loadedSurface == NULL )
		{
			printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
		}
		else
		{
			newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
			if( newTexture == NULL )
			{
				printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
			}

			SDL_FreeSurface( loadedSurface );
		}

		return newTexture;
	}
	
	
	bool CollisionControll()
	{
		bool ansv = false;
		Object *t = &tank;
		for(Wall* w : walls)
		{
			Object *ww = &(*w);
			//bool b = t->checkColl(&(*ww)))
			if ( t->checkColl(&(*ww)) == true)
			{
				ansv = true;
			}	
		}
		return ansv;
	}
	
	
	void Proccess()
	{
		if (!CollisionControll())
		{
			tank.Update();
		}
		
	}
	
	void Clear()
	{
		SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0xFF );
		
		SDL_RenderClear( gRenderer );
	}
	
	void SetTargetFPS(unsigned fps)
    {
        if (fps == 0) fps = 1000;
        target_fps = fps;

        frame_delay = (unsigned)round(1000.0f / fps);
    }
	
	
	void Draw(SDL_Texture* testTexture, SDL_Texture* bulletImg)
	{	
	
		if ( !bullets.empty() )
		{
			for(int i = 0; i < bullets.size(); i++)
			{
				bullets[i]->update();
				SDL_RenderCopyEx(gRenderer, bulletImg, NULL, bullets[i]->GetRect(), 0, NULL, SDL_FLIP_HORIZONTAL);
		
			}
			
			std::cout << "size of bullets is " << bullets.size() << std::endl;
		}
		
		// render walls
		for(Wall* wall : walls)
		{
			SDL_RenderCopyEx(gRenderer, bulletImg, NULL, wall->getSrc(), 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		
		//render Player heatbox 			TODO: delete
		SDL_RenderCopyEx(gRenderer, bulletImg, NULL, tank.GetHeatbox(), 0, NULL, SDL_FLIP_HORIZONTAL);
		
		//render Players
		for(Player* tank : players)
		{
			SDL_RenderCopyEx(gRenderer, testTexture, NULL, tank->GetRect(), tank->GetDegrees()+90, NULL, SDL_FLIP_HORIZONTAL);	
		}
		
		//Обновление экрана
		SDL_RenderPresent( gRenderer );
	}
	
	
	int init()
	{
		SetTargetFPS(60);
		
		//Initialize SDL
		if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		{
			printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
			return -1;
		}
		else
		{
			//Create window
			window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
			if( window == NULL )
			{
				printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
				return -1;
			}
			else
			{
				bool quit = false;
				
				gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
				
				gTexture = loadTexture( "img/tank.png" );
				bulletTestImg = loadTexture( "img/to_test.png" );
				
				
			}
		}
		
		return 0;
		
	}
	
	void play()
	{
		
		while( !quit )
		{
			while( SDL_PollEvent( &e ) != 0 )
			{
				if( e.type == SDL_QUIT )
				{
					quit = true;
				}
				else if( e.type == SDL_KEYDOWN )
				{
					
					if( e.key.keysym.sym == SDLK_w )
					{
						tank.MoveUp();
					}
					if( e.key.keysym.sym == SDLK_s )
					{
						tank.MoveDown();
					}
					if( e.key.keysym.sym == SDLK_a )
					{
						tank.MoveLeft();
					}
					if( e.key.keysym.sym == SDLK_d )
					{
						tank.MoveRight();
					}
					if( e.key.keysym.sym == SDLK_SPACE )
					{
						//tank.shoot();
						
						bullets.push_back(
													new Bullet(tank.GetDegrees(), 
																	tank.getX(), 
																	tank.getY()
																		));
						
						
					}
				}
				else if( e.type == SDL_KEYUP )
				{
					
					if( e.key.keysym.sym == SDLK_w )
					{
						tank.StopUp();
					}
					if( e.key.keysym.sym == SDLK_s )
					{
						tank.StopDown();
					}
					if( e.key.keysym.sym == SDLK_a )
					{
						tank.StopLeft();
					}
					if( e.key.keysym.sym == SDLK_d )
					{
						tank.StopRight();
					}
				}
				
			}
			
			time_frame_start = SDL_GetTicks();
			time_next_frame = time_frame_start + frame_delay;
			
			
			
			Proccess();
			
			Clear();
			
			Draw(gTexture, bulletTestImg);
			
			
			
			
			time_frame_end = SDL_GetTicks();
			sleep_duration = (time_frame_end < time_next_frame) ? (time_next_frame - time_frame_end) : 0;

			SDL_Delay(sleep_duration);
		}		
	}
	
	void destroy()
	{
		SDL_DestroyRenderer( gRenderer );
		SDL_DestroyWindow( window );
		window = NULL;
		gRenderer = NULL;	
		
		if ( !bullets.empty() )
		{
			for(int i = 0; i < bullets.size(); i++)
			{
				bullets[i]->~Bullet();
			}	
		}

		if ( !walls.empty() )
		{
			for(int i = 0; i < walls.size(); i++)
			{
				walls[i]->~Wall();
			}	
		}
		
		if ( !players.empty() )
		{
			for(int i = 0; i < players.size(); i++)
			{
				players[i]->~Player();
			}	
		}
		
		SDL_DestroyWindow( window );
		SDL_Quit();
	}

public:

	Game()
	{
		std::cout << "hi" << std::endl;
	}

	void start()
	{
		
		#include "../Map1.map"
		
		init();
		play();
		destroy();
	}
	
	
	
	
	
	
	
};
#endif