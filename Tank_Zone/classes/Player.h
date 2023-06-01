#ifndef Player_H
#define Player_H

#include "Object.h"
#include <math.h>
#define PI 3.14159265

class Player : public Object
{
private:
	
	int playerID = 1;
	int color = 1;
	float speed = 1.5;
	float rotate = 5.0;
	//float velocity = 0.0;
	float degrees = -90;
	
	SDL_Keycode Key_MoveUp = SDLK_w;
	SDL_Keycode Key_MoveDown = SDLK_s;
	SDL_Keycode Key_TurnRight = SDLK_d;
	SDL_Keycode Key_TurnLeft = SDLK_a;
	SDL_Keycode Key_Fire = SDLK_l;
	
	bool up = false;
	bool down = false;
	bool right = false;
	bool left = false;
	
	
	float x = 100;
	float y = 100;
	
	int w = 25; //125
	int h = 35; //175
	
	//float gip1 = w/cos(degrees*PI/180);
	float gip1 = sqrt(w*w + h*h); // Pifagor
	float startDegR = 90 - 54.462322; // гипотенуза изначально находиться по оперделённфм градусом tan-1(h/w)
	float startDegL = 90 + 54.462322; // гипотенуза изначально находиться по оперделённфм градусом tan-1(h/w)
	
	
	SDL_Rect rect = { x, y, w, h };
	SDL_Rect heatbox = { x, y, w, h };
public:
	
	Player()
	{
		
	}
	
	SDL_Keycode* GetUp() { return &Key_MoveUp; }
	SDL_Keycode* GetDown() { return &Key_MoveDown; }
	SDL_Keycode* GetRight() { return &Key_TurnRight; }
	SDL_Keycode* GetLeft() { return &Key_TurnLeft; }
	
	
	int GetDegrees() { return degrees; }
	
	float getX() { return x;}
	float getY() { return y;}
	
	void MoveUp() { up = true; }
	void MoveDown() { down = true; }
	void MoveRight() { right = true; }
	void MoveLeft() { left = true; }
	
	void StopUp() { up = false; }
	void StopDown() { down = false; }
	void StopRight() { right = false; }
	void StopLeft() { left = false; }
	
	void Update()
	{
		
		float Cx = speed * sin(degrees * rotate); 
		float Cy = speed * sin(degrees * rotate); 
		
		if(up)
		{
			//y -= speed;
			//calculate();
			x += speed * cos(degrees*PI/180); 
			y += speed * sin(degrees*PI/180); 
			
			
			
			//		w = x - (speed * cos(degrees*PI/180));
			//		h = y - (speed * sin(degrees*PI/180));
			
			
			
			
		}
		
		if(down)
		{
			
			
			
			x -= speed * cos(degrees*PI/180); 
			y -= speed * sin(degrees*PI/180); 
			
			
			//		w = x - (speed * cos(degrees*PI/180));
			//		h = y - (speed * sin(degrees*PI/180));
			
			
			
		}
		
		if(right)
		{
			//		w += (speed * cos(degrees*PI/180));
			//		h += (speed * sin(degrees*PI/180));
			
			degrees += rotate;
			if (degrees > 180) { degrees = -180; }
			//calculate();
		}
		
		if(left)
		{
					//w += (speed * cos(degrees*PI/180));
					//h += (speed * sin(degrees*PI/180));
			
			degrees -= rotate;
			if (degrees < -180) { degrees = 180; }
			//calculate();
		}
		
		// ugol
		//w
		float wR = (gip1 * cos((degrees + startDegR)*PI/180)); // 
		float wL = (gip1 * cos((degrees + startDegL)*PI/180)); // 
		
		wR = wR<0 ? -wR: wR;
		wL = wL<0 ? -wL: wL;
		
		w = wR>wL ? wR : wL;
		
		
		// h
		
		float hR = (gip1 * sin((degrees + startDegR)*PI/180)); // 
		float hL = (gip1 * sin((degrees + startDegL)*PI/180)); // 
		
		hR = hR<0 ? -hR: hR;
		hL = hL<0 ? -hL: hL;
		
		h = hR>hL ? hR : hL;
		
		
		
		
		//h += (speed * sin(degrees*PI/180));
		
		
		
		
		std::cout << "degrees =" << degrees << std::endl;
		std::cout << "x = " << x << std::endl;
		std::cout << "y = " << y << std::endl;
		
		std::cout << "w = " << w << std::endl;
		std::cout << "h = " << h << std::endl;
		
		//std::cout << "cos = " << (speed * cos(degrees*PI/180)) << std::endl;
		//std::cout << "sin = " << (speed * sin(degrees*PI/180)) << std::endl << std::endl;
		std::cout << "cos R = " << cos((degrees + startDegR)*PI/180) << std::endl;
		std::cout << "cos L = " << cos((degrees + startDegL)*PI/180) << std::endl;
		std::cout << std::endl;
		
	}
	
	/*
	void calculate()
	{
		std::cout << "x = " << x << std::endl;
		std::cout << "y = " << y << std::endl << std::endl;
		
		x = x + speed * cos(degrees); 
		y = y + speed * sin(degrees); 
	}
	*/
	
	
	SDL_Rect* GetRect()
	{
		rect.x = x;
		rect.y = y;
		
		//rect.w = w;
		//rect.h = h;
		
		return &rect;
	}
	
	SDL_Rect* GetHeatbox() 
	{
		heatbox.x = x + rect.w/2 - w/2;
		heatbox.y = (y + rect.h/2 - h/2); // +30 / + 200
		
		heatbox.w = w;
		heatbox.h = h;
		
		return &heatbox;
	}
	
	void shoot()
	{
		
	}
	
};















#endif