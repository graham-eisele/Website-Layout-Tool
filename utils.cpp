#include "utils.h"
#include "Box.h"
#include <iostream>

template <class E>

void utils<E>::drawElement(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, E e)
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

    //if the element is a box
    if(e.getElementID() == 1)
    {
        std::cout << "Box Element" << std::endl;
        std::cout << e.getBorderThickness() << std::endl;

        int elementWidth = e.getWidth();
        int elementHeight = e.getHeight();
        int borderThickness = e.getBorderThickness();

        const unsigned char boxfillColor[] = {e.getPrimaryColor().getR(), e.getPrimaryColor().getG(), e.getPrimaryColor().getB()};
        const unsigned char boxoutlineColor[] = {e.getBoxOutlineColor().getR(), e.getBoxOutlineColor().getG(), e.getBoxOutlineColor().getB()};

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
}

template class utils<Box>;