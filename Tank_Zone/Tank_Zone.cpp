#define PI 3.14159265
#define real_sqrt sqrtf
#define real_pow powf
typedef float real;

#include <iostream>

//#include "Program.h"
#include "Vector3.h"
#include "Particle.h"
#include "Player.h"
#include "Program.h"
#include "Application.h"
#include "Wall.h"


int main(int argc, char* argv[])
{
    Application soft{};
    soft.run();

    std::cout << "done" << std::endl;
    return 0;
}