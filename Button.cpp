#include "Button.h"
#include <iostream>


Button::Button(int w, int h, std::string text, int textFontSize, Color textColor, Color primaryColor)
{

    this->width = w;
    this->height = h;

    this->borderThickness = 0;
    this->textColor = textColor;
    this->textFontSize = textFontSize;
    this->primaryBoxColor = primaryColor;
    this->text = text;
}
Button::Button(int w, int h, std::string text, int textFontSize, Color textColor, Color primaryColor, int borderThickness, Color boxOutlineColor)
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
    
    this->primaryBoxColor = primaryColor;
    this->boxOutlineColor = boxOutlineColor;

    this->isRounded = isRounded;

    this->textColor = textColor;

    this->textFontSize = textFontSize;

    this->text = text;
}

Button::Button(int w, int h, std::string text, int textFontSize, Color textColor, Color primaryColor, int borderThickness, Color boxOutlineColor, bool isRounded)
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
    
    this->primaryBoxColor = primaryColor;
    this->boxOutlineColor = boxOutlineColor;

    this->textColor = textColor;

    this->textFontSize = textFontSize;

    this->text = text;

    this->isRounded = isRounded;
}

Button::Button(int w, int h, std::string text, int textFontSize, Color textColor, Color primaryColor, int borderThickness, Color boxOutlineColor, bool isRounded, bool isCentered)
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
    
    this->primaryBoxColor = primaryColor;
    this->boxOutlineColor = boxOutlineColor;

    this->textColor = textColor;

    this->textFontSize = textFontSize;

    this->text = text;

    this->isRounded = isRounded;
    this->isCentered = isCentered;
}

const int Button::getWidth()
{
    return width;
}

const int Button::getHeight()
{
    return height;
}

const int Button::getBorderThickness()
{
    return borderThickness;
}

const int Button::getTextFontSize()
{
    return textFontSize;
}

Color Button::getPrimaryColor()
{
    return primaryBoxColor;
}

Color Button::getBoxOutlineColor()
{
    return boxOutlineColor;
}

Color Button::getTextColor()
{
    return textColor;
}

std::string Button::getText()
{
    return text;
}

bool Button::Centered()
{
    return isCentered;
}

bool Button::Rounded()
{
    return isRounded;
}

