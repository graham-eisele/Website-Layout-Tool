#ifndef BUTTON_H
#define BUTTON_H
#include "Color.h"
#include "Box.h"
#include "Text.h"
#include <iostream>

class Button
{
public:
    //default box constructor
    Button(std::string id, int w, int h, std::string text, int textFontSize, Color textColor, Color primaryColor, int borderThickness, Color boxOutlineColor, bool buttonRounded, bool buttonTextCentered);

    const int getWidth();
    const int getHeight();
    const int getBorderThickness();
    const int getTextFontSize();
    
    Color getTextColor();
    Color getPrimaryColor();
    Color getBoxOutlineColor();

    std::string getText();

    bool isRounded();
    bool isTextCentered();

    std::string getId();

    void setIndex(int index);
    int getIndex();

private:
    
    int width;
    int height;
    int borderThickness;
    int textFontSize;

    Color primaryBoxColor;
    Color boxOutlineColor;

    Color textColor;
    std::string text;

    bool buttonRounded;
    bool textCentered;

    std::string id;

    int index;

};
#endif