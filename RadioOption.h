#ifndef RADIOOPTION_H
#define RADIOOPTION_H
#include "Color.h"
#include "Box.h"
#include "Text.h"
#include <iostream>

class RadioOption
{
public:
    //default box constructor
    RadioOption(int w, int h, std::string text, int textFontSize, Color textColor, Color boxFillColor, Color circleFillColor, Color cirlceOutlineColor);
    RadioOption(int w, int h, std::string text, int textFontSize, Color textColor, Color boxFillColor, Color circleFillColor, Color circleOutlineColor, int borderThickness, Color boxOutlineColor);
    RadioOption(int w, int h, std::string text, int textFontSize, Color textColor, Color boxFillColor, Color circleFillColor, Color circleOutlineColor, int borderThickness, Color boxOutlineColor, bool buttonRounded);
    RadioOption(int w, int h, std::string text, int textFontSize, Color textColor, Color boxFillColor, Color circleFillColor, Color circleOutlineColor, int borderThickness, Color boxOutlineColor, bool buttonRounded, bool buttonTextCentered);

    const int getWidth();
    const int getHeight();
    const int getBorderThickness();
    const int getTextFontSize();
    
    Color getTextColor();
    Color getPrimaryColor();
    Color getBoxOutlineColor();

    Color getCircleFillColor();
    Color getCircleOutlineColor();

    std::string getText();

    bool isRounded();
    bool isTextCentered();

private:
    
    int width;
    int height;
    int borderThickness;
    int textFontSize;

    Color primaryBoxColor;
    Color boxOutlineColor;

    Color circleFillColor;
    Color circleOutlineColor;

    Color textColor;
    std::string text;

    bool radioOptionRounded;
    bool textCentered;

};
#endif