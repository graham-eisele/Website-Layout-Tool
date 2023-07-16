#include "TextBox.h"
#include <iostream>

TextBox::TextBox(int w, int h, std::string hintText, int textFontSize, int borderThickness, Color hintTextColor, Color boxFillColor, Color boxOutlineColor, Color underLineColor, bool textBoxRounded, bool textboxTextCentered, bool hasUnderLine)
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
    
    //setting color attributes
    this->primaryBoxColor = boxFillColor;
    this->boxOutlineColor = boxOutlineColor;
    this->underLineColor = underLineColor;
    this->hintTextColor = hintTextColor;

    this->textFontSize = textFontSize;

    this->hintText = hintText;

    this->textBoxRouned = textBoxRounded;
    this->textCentered = textboxTextCentered;

    this->hasUnderline = hasUnderLine;
}

const int TextBox::getWidth()
{
    return width;
}

const int TextBox::getHeight()
{
    return height;
}

const int TextBox::getBorderThickness()
{
    return borderThickness;
}

const int TextBox::getTextFontSize()
{
    return textFontSize;
}

Color TextBox::getPrimaryColor()
{
    return primaryBoxColor;
}

Color TextBox::getBoxOutlineColor()
{
    return boxOutlineColor;
}

Color TextBox::getTextColor()
{
    return hintTextColor;
}

Color TextBox::getUnderLineColor()
{
    return underLineColor;
}

std::string TextBox::getHintText()
{
    return hintText;
}

bool TextBox::isTextCentered()
{
    return textCentered;
}

bool TextBox::isRounded()
{
    return textBoxRouned;
}

bool TextBox::isUnderlined()
{
    return hasUnderline;
}