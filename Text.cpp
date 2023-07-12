#include "Text.h"
#include <iostream>
#include <string>


Text::Text(int f, std::string text, Color textColor)
{
    this->fontSize = f;

    this->textColor = textColor;

    this->text = text;

    
}

Color Text::getTextColor()
{
    return textColor;
}

std::string Text::getText()
{
    return text;
}

int Text::getFontSize()
{
    return fontSize;
}