#include "../headers/Box.h"
#include <iostream>

Box::Box(std::string id, int w, int h, Color primaryColor, int borderThickness, Color boxOutlineColor)
{   
    this->id = id;
    
    this->width = w;
    this->height = h;

    if(borderThickness <= w && borderThickness <= h)
    {
        this->borderThickness = borderThickness;
    }
    else
    {
        this->borderThickness = 0;
    }
    
    this->primaryColor = primaryColor;
    this->boxOutlineColor = boxOutlineColor;
}

const int Box::getWidth()
{
    return width;
}

const int Box::getHeight()
{
    return height;
}

const int Box::getBorderThickness()
{
    return borderThickness;
}

Color Box::getPrimaryColor()
{
    return primaryColor;
}

Color Box::getBoxOutlineColor()
{
    return boxOutlineColor;
}

std::string Box::getId()
{
    return id;
}

void Box::setIndex(int index)
{
    this->index = index;
}
int Box::getIndex()
{
    return index;
}