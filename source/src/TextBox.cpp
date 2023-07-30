#include "../headers/TextBox.h"
#include "../headers/utils.h"
#include <iostream>

TextBox::TextBox(std::string id, int w, int h, std::string hintText, int textFontSize, int borderThickness, Color hintTextColor, Color boxFillColor, Color boxOutlineColor, Color underLineColor, bool textBoxRounded, bool textboxTextCentered, bool hasUnderLine)
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

std::string TextBox::getId()
{
    return id;
}

void TextBox::setIndex
(int index)
{
    this->index = index;
}
int TextBox::getIndex()
{
    return index;
}

void TextBox::mutate()
{
    this->width = utils::mutateInt(width, 1920);
    this->height = utils::mutateInt(height, 1080);

    this->borderThickness = utils::mutateInt(borderThickness, 20);
    this->textFontSize = utils::mutateInt(height, 100);

    this->primaryBoxColor = utils::mutateColor(primaryBoxColor);
    this->boxOutlineColor = utils::mutateColor(boxOutlineColor);
    this->underLineColor = utils::mutateColor(underLineColor);
    this->hintTextColor = utils::mutateColor(hintTextColor);

    this->hintText = utils::mutateString(hintText);

    this->textBoxRouned = utils::randomBool();
    this->textCentered = utils::randomBool();
    this->hasUnderline = utils::randomBool();
}