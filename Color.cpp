#include "Color.h"

Color::Color()
{
    r = 0;
    g = 0;
    b = 0;
}

Color::Color(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

int Color::getR()
{
    return r;
}

int Color::getG()
{
    return g;
}

int Color::getB()
{
    return b;
}
