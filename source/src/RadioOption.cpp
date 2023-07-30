#include "../headers/RadioOption.h"
#include "../headers/utils.h"
#include <iostream>

RadioOption::RadioOption(std::string id, int w, int h, std::string text, int textFontSize, Color textColor, Color boxFillColor, Color circleFillColor, Color circleOutlineColor, int borderThickness, Color boxOutlineColor, bool buttonRounded, bool buttonTextCentered)
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
    
    this->primaryBoxColor = boxFillColor;
    this->boxOutlineColor = boxOutlineColor;

    this->textColor = textColor;

    this->textFontSize = textFontSize;

    this->text = text;

    this->radioOptionRounded = buttonRounded;
    this->textCentered = buttonTextCentered;

    this->circleFillColor = circleFillColor;
    this->circleOutlineColor = circleOutlineColor;
}

const int RadioOption::getWidth()
{
    return width;
}

const int RadioOption::getHeight()
{
    return height;
}

const int RadioOption::getBorderThickness()
{
    return borderThickness;
}

const int RadioOption::getTextFontSize()
{
    return textFontSize;
}

Color RadioOption::getPrimaryColor()
{
    return primaryBoxColor;
}

Color RadioOption::getBoxOutlineColor()
{
    return boxOutlineColor;
}

Color RadioOption::getTextColor()
{
    return textColor;
}

Color RadioOption::getCircleFillColor()
{
    return circleFillColor;
}

Color RadioOption::getCircleOutlineColor()
{
    return circleOutlineColor;
}

std::string RadioOption::getText()
{
    return text;
}

bool RadioOption::isTextCentered()
{
    return textCentered;
}

bool RadioOption::isRounded()
{
    return radioOptionRounded;
}

std::string RadioOption::getId()
{
    return id;
}

void RadioOption::setIndex(int index)
{
    this->index = index;
}
int RadioOption::getIndex()
{
    return index;
}

void RadioOption::mutate()
{

    bool radioOptionRounded;
    bool textCentered;

    this->width = utils::mutateInt(width, 1920);
    this->height = utils::mutateInt(height, 1080);
    this->borderThickness = utils::mutateInt(borderThickness, 40);
    this->textFontSize = utils::mutateInt(textFontSize, 100);

    this->primaryBoxColor = utils::mutateColor(primaryBoxColor);
    this->boxOutlineColor = utils::mutateColor(boxOutlineColor);
    this->circleFillColor = utils::mutateColor(circleFillColor);
    this->circleOutlineColor = utils::mutateColor(circleOutlineColor);
    this->textColor = utils::mutateColor(textColor);

    this->text = utils::mutateString(this->text);

    this->radioOptionRounded = utils::randomBool();
    this->textCentered = utils::randomBool();
}