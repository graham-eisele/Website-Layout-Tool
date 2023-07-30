#include "../headers/Color.h"

Color::Color()
{
    r = 0;
    g = 0;
    b = 0;
    a = 0;
}

Color::Color(int r, int g, int b, int a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
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

int Color::getA()
{
    return a;
}

void Color::setR(int r)
{
    this->r = r;
}

void Color::setG(int g)
{
    this->g = g;
}

void Color::setB(int b)
{
    this->b = b;
}

void Color::setA(int a)
{  
    this->a = a;
}