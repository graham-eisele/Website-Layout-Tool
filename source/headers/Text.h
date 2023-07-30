#ifndef TEXT_H
#define TEXT_H
#include <string>
#include "Color.h"


class Text
{
public:
    //default box constructor
    Text(std::string id, int f, std::string text, Color textColor);

    Color getTextColor();
     
    std::string getText();
    
    int getFontSize();
    
    int getWidth();
    int getHeight();
    
    std::string getId();

    void setIndex(int index);
    int getIndex();

    void mutate();

private:

    int width;
    int height;
    
    int fontSize;
    Color textColor;
    std::string text;

    std::string id;

    int index;
    
};
#endif