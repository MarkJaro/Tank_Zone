#ifndef Object_H
#define Object_H

#include <iostream>

class Object
{
protected:
	SDL_Rect heatbox;
	
public:
	//SDL_Rect getColl() { return heatbox; }
	
	bool checkColl( Object* o ) 
	{ 
		bool ansv = false;
		
		//std::cout << "hi" << this->heatbox.x + this->heatbox.w << std::endl;
		//std::cout << "hi" << o->heatbox.x - o->heatbox.w << std::endl;
		
		if( this->heatbox.x + this->heatbox.w >= o->heatbox.x - o->heatbox.w)
		{
			ansv = true;
		}
		
		return ansv;
	}
	
};
#endif