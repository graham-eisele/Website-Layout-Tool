#include "../headers/Box.h"
#include "../headers/utils.h"
#include <iostream>

Box::Box(std::string id, int w, int h, Color primaryColor, int borderThickness, Color boxOutlineColor, bool isRounded)
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

    this->isRounded = isRounded;
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

const std::string Box::getId()
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

const bool Box::rounded()
{
    return isRounded;
}

void Box::mutate()
{
    width = utils::mutateInt(width, 1920);
    height = utils::mutateInt(height, 1080);

    borderThickness = utils::mutateInt(borderThickness, 20);

    primaryColor = utils::mutateColor(primaryColor);
    boxOutlineColor = utils::mutateColor(boxOutlineColor);

    isRounded = utils::randomBool();

}