#pragma once
#ifndef PROGRAM_H
#define PROGRAM_H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Program
{

protected:

	// render variables
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Renderer* renderer = NULL;

	// main loop flag
	bool running = true;

	// Event handler
	SDL_Event event;

	// window size
	int windowWidth = 640*2;
	int windowHeight = windowWidth / 2;

	// varibles for track fps
	unsigned target_fps = 60;
	unsigned frame_delay = 16;
	unsigned time_frame_start = 0;
	unsigned time_frame_end = 0;
	unsigned time_next_frame = 0;
	unsigned sleep_duration = 0;


public:

	Program(int windowW = 640*2, int windowH = 640, int targetFps = 60)
	{
		setTargetFPS(60);

		try
		{
			// TODO: create enum for init
			init();
		}
		catch (std::exception e)
		{
			destroy();
			throw e;
		}
	}

	void init()
	{
		// SDL init
		int sdl_init = SDL_Init(SDL_INIT_VIDEO);

		if (sdl_init < 0)
		{
			printf("SDL INIT ERROR");
		}
		

		// Window init
		window = SDL_CreateWindow( "Tank Zone", SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN );

		bool windowIsNull = window == NULL;

		if (windowIsNull)
		{
			printf("SDL Window init error");
		}
		

		// Buffer init
		screenSurface = SDL_GetWindowSurface(window);

		bool surfaceIsNull = screenSurface == NULL;

		if (surfaceIsNull)
		{
			printf("Screen surface error");
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		bool rendererIsNull = screenSurface == NULL;

		if (rendererIsNull)
		{
			printf("Renderer error");
		}

	}

	void run()
	{
		// while application is running
		while (running)
		{
			// Update Timer
			time_frame_start = SDL_GetTicks();
			time_next_frame = time_frame_start + frame_delay;

			handleEvents();

			process();

			render();

			// wait if frame was completed too fast
			time_frame_end = SDL_GetTicks();
			sleep_duration = (time_frame_end < time_next_frame) ? (time_next_frame - time_frame_end) : 0;
			SDL_Delay(sleep_duration);
		}

		// wait
		//SDL_Delay(7000);

		destroy();
	}

	void destroy()
	{
		SDL_DestroyWindow( window );

		SDL_Quit();
	}
	
	void setTargetFPS(unsigned fps)
	{
		if (fps == 0) fps = 1000;
		target_fps = fps;

		frame_delay = (unsigned)round(1000.0f / fps);
	}


protected:

	virtual void handleEvents()
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}
	}

	virtual void process()
	{
		
	}

	virtual void render()
	{
		// fill bg
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 255));

		// update screen
		SDL_UpdateWindowSurface(window);
	}

	SDL_Texture* loadTexture(std::string path)
	{
		SDL_Texture* newTexture = NULL;

		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == NULL)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		}
		else
		{
			newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			if (newTexture == NULL)
			{
				printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			}

			SDL_FreeSurface(loadedSurface);
		}

		return newTexture;
	}
	

};

#endif









