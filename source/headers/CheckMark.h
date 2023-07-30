#ifndef CHECKMARK_H
#define CHECKMARK_H
#include "Color.h"
#include "Box.h"
#include "Text.h"
#include <string>

class CheckMark
{
public:
    //default box constructor
    CheckMark(std::string id, int w, int h, std::string text, int textFontSize, Color textColor, Color checkmarkBoxFillColor, Color checkmarkBoxOutlineColor, Color containerFillColor, Color containerOutlineColor, int borderThickness, bool containerRounded, bool buttonTextCentered, bool checkMarkBoxRounded);

    const int getWidth();
    const int getHeight();
    const int getBorderThickness();
    const int getTextFontSize();
    
    Color getTextColor();
    Color getContainerFillColor();
    Color getContainerOutlineColor();

    Color getCheckmarkBoxFillColor();
    Color getCheckmarkBoxOutlineColor();

    std::string getText();

    bool isContainerRounded();
    bool isCheckmarkBoxRounded();
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

    Color containerFillColor;
    Color containerOutlineColor;

    Color checkmarkBoxFillColor;
    Color checkmarkBoxOutlineColor;

    Color textColor;
    std::string text;

    bool checkmarkContainerRounded;
    bool textCentered;
    bool checkmarkBoxRounded;

    std::string id;

    int index;

};
#endif