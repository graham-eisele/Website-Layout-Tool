#ifndef TEXT_H
#define TEXT_H
#include <string>
#include "Text.h"
#include "Color.h"


class Text
{
public:
    //default box constructor
    Text(int f, std::string text, Color textColor);

    Color getTextColor();
     
    std::string getText();
    
    int getFontSize();
    
    int getWidth();
    int getHeight();

private:

    int width;
    int height;
    
    int fontSize;
    Color textColor;
    std::string text;
    
};
#endif