#include "Box.h"
#include <iostream>


Box::Box(int w, int h, Color primaryColor)
{
    setElementID(1);

    this->width = w;
    this->height = h;

    this->borderThickness = 0;
}
Box::Box(int w, int h, Color primaryColor, int borderThickness, Color boxOutlineColor)
{   
    setElementID(1);

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
