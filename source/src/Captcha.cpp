#include "../headers/Captcha.h"
#include "../headers/utils.h"
#include <iostream>

Captcha::Captcha(std::string id, int w)
{   
    this->id = id;
    
    this->width = w;

}

const int Captcha::getWidth()
{
    return width;
}

std::string Captcha::getId()
{
    return id;
}

void Captcha::setIndex(int index)
{
    this->index = index;
}
int Captcha::getIndex()
{
    return index;
}

void Captcha::mutate()
{
    width = utils::mutateInt(width, 1920);
}