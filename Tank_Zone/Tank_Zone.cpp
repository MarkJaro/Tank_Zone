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

/*
class A
{
protected:
    void virtual print()
    {
        std::cout << "A" << std::endl;
    }
};

class B : A
{
public:
    B() {}

    void print() override
    {
        A::print();
        std::cout << "B" << std::endl;
    }
};
*/

int main(int argc, char* argv[])
{
    /*
    B b{};
    b.print();
    */

    Application soft{};
    soft.run();


    std::cout << "done" << std::endl;
    return 0;
}