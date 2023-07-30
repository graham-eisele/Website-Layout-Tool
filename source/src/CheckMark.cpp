#include "../headers/CheckMark.h"
#include "../headers/utils.h"
#include <iostream>

CheckMark::CheckMark(std::string id, int w, int h, std::string text, int textFontSize, Color textColor, Color checkmarkBoxFillColor, Color checkmarkBoxOutlineColor, Color containerFillColor, Color containerOutlineColor, int borderThickness, bool containerRounded, bool buttonTextCentered, bool checkMarkBoxRounded)
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
    
    this->containerFillColor = containerFillColor;
    this->containerOutlineColor = containerOutlineColor;

    this->textColor = textColor;

    this->textFontSize = textFontSize;

    this->text = text;

    this->checkmarkContainerRounded = containerRounded;
    this->textCentered = buttonTextCentered;
    this->checkmarkBoxRounded = checkMarkBoxRounded;

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

bool CheckMark::isContainerRounded()
{
    return checkmarkContainerRounded;
}

bool CheckMark::isCheckmarkBoxRounded()
{
    return checkmarkBoxRounded;
}

std::string CheckMark::getId()
{
    return id;
}

void CheckMark::setIndex(int index)
{
    this->index = index;
}
int CheckMark::getIndex()
{
    return index;
}

void CheckMark::mutate()
{

    width = utils::mutateInt(width, 1920);
    height = utils::mutateInt(height, 1080);

    borderThickness = utils::mutateInt(borderThickness, 20);
    textFontSize = utils::mutateInt(borderThickness, 100);

    containerFillColor = utils::mutateColor(containerFillColor);
    containerOutlineColor = utils::mutateColor(containerOutlineColor);

    checkmarkBoxFillColor = utils::mutateColor(checkmarkBoxFillColor);
    checkmarkBoxOutlineColor = utils::mutateColor(checkmarkBoxOutlineColor);

    textColor = utils::mutateColor(textColor);

    text = utils::mutateString(text);

    checkmarkContainerRounded = utils::randomBool(); 
    textCentered = utils::randomBool();
    checkmarkBoxRounded = utils::randomBool();
}