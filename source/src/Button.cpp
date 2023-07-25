#include "../headers/Button.h"
#include <iostream>


Button::Button(std::string id, int w, int h, std::string text, int textFontSize, Color textColor, Color primaryColor, int borderThickness, Color boxOutlineColor, bool buttonRounded, bool buttonTextCentered)
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
    
    this->primaryBoxColor = primaryColor;
    this->boxOutlineColor = boxOutlineColor;

    this->textColor = textColor;

    this->textFontSize = textFontSize;

    this->text = text;

    this->buttonRounded = buttonRounded;
    this->textCentered = buttonTextCentered;
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

bool Button::isTextCentered()
{
    return textCentered;
}

bool Button::isRounded()
{
    return buttonRounded;
}

std::string Button::getId()
{
    return id;
}

void Button::setIndex(int index)
{
    this->index = index;
}
int Button::getIndex()
{
    return index;
}