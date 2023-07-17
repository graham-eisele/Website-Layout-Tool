#include "../headers/CheckMark.h"
#include <iostream>

CheckMark::CheckMark(int w, int h, std::string text, int textFontSize, Color textColor, Color checkmarkBoxFillColor, Color checkmarkBoxOutlineColor, Color containerFillColor, Color containerOutlineColor, int borderThickness, bool containerRounded, bool buttonTextCentered, bool checkMarkBoxRounded)
{   
    
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
    
    this->containerFillColor = containerFillColor;
    this->containerOutlineColor = containerOutlineColor;

    this->textColor = textColor;

    this->textFontSize = textFontSize;

    this->text = text;

    this->checkmarkContainerRounded = containerRounded;
    this->textCentered = buttonTextCentered;

    this->checkmarkBoxFillColor = checkmarkBoxFillColor;
    this->checkmarkBoxOutlineColor = checkmarkBoxOutlineColor;
}

const int CheckMark::getWidth()
{
    return width;
}

const int CheckMark::getHeight()
{
    return height;
}

const int CheckMark::getBorderThickness()
{
    return borderThickness;
}

const int CheckMark::getTextFontSize()
{
    return textFontSize;
}

Color CheckMark::getCheckmarkBoxFillColor()
{
    return checkmarkBoxFillColor;
}

Color CheckMark::getCheckmarkBoxOutlineColor()
{
    return checkmarkBoxOutlineColor;
}

Color CheckMark::getTextColor()
{
    return textColor;
}

Color CheckMark::getContainerFillColor()
{
    return containerFillColor;
}

Color CheckMark::getContainerOutlineColor()
{
    return containerOutlineColor;
}

std::string CheckMark::getText()
{
    return text;
}

bool CheckMark::isTextCentered()
{
    return textCentered;
}

bool CheckMark::isRounded()
{
    return checkmarkContainerRounded;
}

