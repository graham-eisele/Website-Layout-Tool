#ifndef BOX_H
#define BOX_H
#include "Color.h"
#include <string>

class Box
{
public:
    //default box constructor
    Box(std::string id, int w, int h, Color primaryColor, int borderThickness, Color boxOutlineColor);

    const int getWidth();
    const int getHeight();
    const int getBorderThickness();

    Color getPrimaryColor();
    Color getBoxOutlineColor();

    std::string getId();

    void setIndex(int index);
    int getIndex();

private:
    
    int width;
    int height;

    int borderThickness;

    Color primaryColor;
    Color boxOutlineColor;

    std::string id;

    int index;
    
};
#endif