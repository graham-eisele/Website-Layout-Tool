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
    RadioOption(std::string id, int w, int h, std::string text, int textFontSize, Color textColor, Color boxFillColor, Color circleFillColor, Color circleOutlineColor, int borderThickness, Color boxOutlineColor, bool buttonRounded, bool buttonTextCentered);

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

    std::string getId();

    void setIndex(int index);
    int getIndex();

    void mutate();

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

    std::string id;

    int index;

};
#endif