#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "Color.h"
#include "Box.h"
#include "Text.h"
#include <string>

class TextBox
{
public:
    //default box constructor
    TextBox(std::string id, int w, int h, std::string hintText, int textFontSize, int borderThickness, Color hintTextColor, Color boxFillColor, Color boxOutlineColor, Color underLineColor, bool textBoxRounded, bool textboxTextCentered, bool hasUnderLine);

    const int getWidth();
    const int getHeight();
    const int getBorderThickness();
    const int getTextFontSize();
    
    Color getTextColor();
    Color getPrimaryColor();
    Color getBoxOutlineColor();
    Color getUnderLineColor();

    std::string getHintText();

    bool isRounded();
    bool isTextCentered();
    bool isUnderlined();

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
    Color underLineColor;
    Color hintTextColor;

    std::string hintText;

    bool textBoxRouned;
    bool textCentered;
    bool hasUnderline;

    std::string id;

    int index;

};
#endif