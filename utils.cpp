#include "utils.h"
#include "Box.h"
#include "Text.h"
#include "Button.h"
#include <iostream>
#include <cstdlib>



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

        canvas.draw_text(startX, startY, text.getText().c_str(), textColor,0,1,text.getFontSize());
    
}


void utils::drawButton(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Button button)
{

       //as a percentage of the height
       float vertical_padding = 0.15;
       
       //as a percentage of the height
       float horizontal_padding = 0.25;

       Box box = Box(button.getWidth(), button.getHeight(), button.getPrimaryColor(), button.getBorderThickness(), button.getBoxOutlineColor());

       Text text = Text(button.getTextFontSize(), button.getText(), button.getTextColor());

       drawBox(canvas, startX, startY, box);

       if(button.Centered() == false)
       {
        drawText(canvas, startX + horizontal_padding * button.getWidth(), startY + box.getHeight() / 2 - text.getHeight() / 2, text);
       }
       else
       {
        drawText(canvas, startX + button.getWidth() / 2 - text.getWidth() / 2, startY + box.getHeight() / 2 - text.getHeight() / 2, text);
       }

}
