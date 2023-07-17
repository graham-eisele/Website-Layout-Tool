#ifndef BOX_H
#define BOX_H
#include "Color.h"

class Box
{
public:
    //default box constructor
    Box(int w, int h, Color primaryColor, int borderThickness, Color boxOutlineColor);

    const int getWidth();
    const int getHeight();
    const int getBorderThickness();

    Color getPrimaryColor();
    Color getBoxOutlineColor();

private:
    
    int width;
    int height;

    int borderThickness;

    Color primaryColor;
    Color boxOutlineColor;
    
};
#endif