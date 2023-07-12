#include "utils.h"
#include "Box.h"
#include "Text.h"
#include <iostream>


void utils::drawBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Box box)
{
    if(startX < 0 || startY < 0)
    {
        std::cout << "Invalid starting drawing point. Both X and Y must be greater than 0." << std::endl;
        return;
    }

    if(startX > canvas.width() || startY > canvas.height())
    {
        std::cout << "Invalid starting drawing point. Both X and Y less than or equal to the width and height of the canvas." << std::endl;
        return;
    }

   
    int elementWidth = box.getWidth();
    int elementHeight = box.getHeight();
    int borderThickness = box.getBorderThickness();

    const unsigned char boxfillColor[] = {box.getPrimaryColor().getR(), box.getPrimaryColor().getG(), box.getPrimaryColor().getB()};
    const unsigned char boxoutlineColor[] = {box.getBoxOutlineColor().getR(), box.getBoxOutlineColor().getG(), box.getBoxOutlineColor().getB()};

    if(borderThickness <= 0)
    {
        canvas.draw_rectangle(startX, startY, startX + elementWidth, startY + elementHeight, boxfillColor, 1);
    }
    else if(borderThickness > 0)
    {  
        //filled rectangle
        canvas.draw_rectangle(startX, startY, startX + elementWidth, startY + elementHeight, boxoutlineColor, 1);

        //outline
        canvas.draw_rectangle(startX + borderThickness / 2, startY + borderThickness / 2, startX + elementWidth - borderThickness / 2, startY + elementHeight - borderThickness / 2, boxfillColor, 1);
    }
    
 
}

void utils::drawText(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Text text)
{
  
        const unsigned char textColor[] = {text.getTextColor().getR(), text.getTextColor().getG(), text.getTextColor().getB()};

        canvas.draw_text(0, 0, "Test", textColor,0,1,text.getFontSize());
    
}

