#include "../headers/Text.h"
#include "../headers/CImg.h"
#include <iostream>
#include <string>

Text::Text(std::string id, int f, std::string text, Color textColor)
{
    this->id = id;

    this->fontSize = f;

    this->textColor = textColor;

    this->text = text;

    cimg_library::CImg<unsigned char> bg(1,0,1,3, 255);

    const unsigned char black[] = {255, 255, 255};

    bg.draw_text(0, 0, text.c_str(), black,0,1,this->fontSize);

    this->width = bg.width();
    this->height = bg.height();
    
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

int Text::getWidth()
{
    return width;
}

int Text::getHeight()
{
    return height;
}

std::string Text::getId()
{
    return id;
}

void Text::setIndex(int index)
{
    this->index = index;
}
int Text::getIndex()
{
    return index;
}