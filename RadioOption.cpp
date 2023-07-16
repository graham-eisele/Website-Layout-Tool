#include "RadioOption.h"
#include <iostream>


RadioOption::RadioOption(int w, int h, std::string text, int textFontSize, Color textColor, Color boxFillColor, Color circleFillColor, Color circleOutlineColor)
{

    this->width = w;
    this->height = h;

    this->borderThickness = 0;
    this->textColor = textColor;
    this->textFontSize = textFontSize;
    this->primaryBoxColor = boxFillColor;
    this->text = text;

    this->radioOptionRounded = false;
    this->textCentered = false;

    this->circleFillColor = circleFillColor;
    this->circleOutlineColor = circleOutlineColor;
}
RadioOption::RadioOption(int w, int h, std::string text, int textFontSize, Color textColor, Color boxFillColor, Color circleFillColor, Color circleOutlineColor, int borderThickness, Color boxOutlineColor)
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
    
    this->primaryBoxColor = boxFillColor;
    this->boxOutlineColor = boxOutlineColor;

    this->radioOptionRounded = false;
    this->textCentered = false;

    this->textColor = textColor;

    this->textFontSize = textFontSize;

    this->text = text;

    this->circleFillColor = circleFillColor;
    this->circleOutlineColor = circleOutlineColor;
}

RadioOption::RadioOption(int w, int h, std::string text, int textFontSize, Color textColor, Color boxFillColor, Color circleFillColor, Color circleOutlineColor, int borderThickness, Color boxOutlineColor, bool buttonRounded)
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
    
    this->primaryBoxColor = boxFillColor;
    this->boxOutlineColor = boxOutlineColor;

    this->textColor = textColor;

    this->textFontSize = textFontSize;

    this->text = text;

    this->radioOptionRounded = buttonRounded;
    this->textCentered = false;

    this->circleFillColor = circleFillColor;
    this->circleOutlineColor = circleOutlineColor;
}

RadioOption::RadioOption(int w, int h, std::string text, int textFontSize, Color textColor, Color boxFillColor, Color circleFillColor, Color circleOutlineColor, int borderThickness, Color boxOutlineColor, bool buttonRounded, bool buttonTextCentered)
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
