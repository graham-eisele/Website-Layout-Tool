#ifndef BOX_H
#define BOX_H
#include "Color.h"
#include <string>

class Box
{
public:
    //default box constructor
    Box(std::string id, int w, int h, Color primaryColor, int borderThickness, Color boxOutlineColor, bool isRounded);
    
    const int getWidth();
    const int getHeight();
    const int getBorderThickness();


    const bool rounded();

    Color getPrimaryColor();
    Color getBoxOutlineColor();

    const std::string getId();

    void setIndex(int index);
    int getIndex();

    void mutate();

private:
    
    int width;
    int height;

    int borderThickness;

    Color primaryColor;
    Color boxOutlineColor;

    std::string id;

    int index;

    bool isRounded;
    
};
#endif