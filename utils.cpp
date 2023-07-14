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
        //outline
        canvas.draw_rectangle(startX, startY, startX + elementWidth, startY + elementHeight, boxoutlineColor, 1);

        //filled rectangle
        canvas.draw_rectangle(startX + borderThickness, startY + borderThickness, startX + elementWidth - borderThickness, startY + elementHeight - borderThickness, boxfillColor, 1);
    }
    
 
}

void utils::drawRoundedBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Box box)
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

    float circle_radius = 0.15 * box.getWidth();

    if(borderThickness <= 0)
    {
        

        //top left circle
        canvas.draw_circle(startX + circle_radius, startY + circle_radius, circle_radius, boxfillColor, 1);

        //bottom left box
        canvas.draw_circle(startX + circle_radius, startY - circle_radius + elementHeight, circle_radius, boxfillColor, 1);

        //top right circle
        canvas.draw_circle(startX - circle_radius + elementWidth, startY + circle_radius, circle_radius, boxfillColor, 1);

        //bottom right cirlce
        canvas.draw_circle(startX - circle_radius + elementWidth, startY - circle_radius + elementHeight, circle_radius, boxfillColor, 1);

        //horizonal rectangle
        canvas.draw_rectangle(startX, startY + circle_radius, startX + elementWidth, startY + elementHeight - circle_radius, boxfillColor, 1);

        //vertical rectangle
        canvas.draw_rectangle(startX + circle_radius, startY, startX + elementWidth - circle_radius, startY + elementHeight, boxfillColor, 1);
    }
    else if(borderThickness > 0)
    {  
        std::cout << "test" << std::endl;

        //outline
        //top left circle
        canvas.draw_circle(startX + circle_radius, startY + circle_radius, circle_radius, boxoutlineColor, 1);

        //bottom left box
        canvas.draw_circle(startX + circle_radius, startY - circle_radius + elementHeight, circle_radius, boxoutlineColor, 1);

        //top right circle
        canvas.draw_circle(startX - circle_radius + elementWidth, startY + circle_radius, circle_radius, boxoutlineColor, 1);

        //bottom right cirlce
        canvas.draw_circle(startX - circle_radius + elementWidth, startY - circle_radius + elementHeight, circle_radius, boxoutlineColor, 1);

        //horizonal rectangle
        canvas.draw_rectangle(startX, startY + circle_radius, startX + elementWidth, startY + elementHeight - circle_radius, boxoutlineColor, 1);

        //vertical rectangle
        canvas.draw_rectangle(startX + circle_radius, startY, startX + elementWidth - circle_radius, startY + elementHeight, boxoutlineColor, 1);

        /***/

        //filled rectangle
        //top left circle
        canvas.draw_circle(startX + circle_radius + borderThickness, startY + circle_radius + borderThickness, circle_radius, boxfillColor, 1);

        //bottom left box
        canvas.draw_circle(startX + circle_radius + borderThickness, startY - circle_radius + elementHeight - borderThickness, circle_radius, boxfillColor, 1);

        //top right circle
        canvas.draw_circle(startX - circle_radius + elementWidth - borderThickness, startY + circle_radius + borderThickness, circle_radius, boxfillColor, 1);

        //bottom right cirlce
        canvas.draw_circle(startX - circle_radius + elementWidth - borderThickness, startY - circle_radius + elementHeight - borderThickness, circle_radius, boxfillColor, 1);

        //horizonal rectangle
        canvas.draw_rectangle(startX + borderThickness, startY + circle_radius, startX + elementWidth - borderThickness, startY + elementHeight - circle_radius, boxfillColor, 1);

        //vertical rectangle
        canvas.draw_rectangle(startX + circle_radius, startY + borderThickness, startX + elementWidth - circle_radius, startY + elementHeight - borderThickness, boxfillColor, 1);

        

       
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
       float horizontal_padding = 0.25;

       Box box = Box(button.getWidth(), button.getHeight(), button.getPrimaryColor(), button.getBorderThickness(), button.getBoxOutlineColor());

       Text text = Text(button.getTextFontSize(), button.getText(), button.getTextColor());

       const unsigned char buttonPrimaryColor[] = {button.getPrimaryColor().getR(), button.getPrimaryColor().getG(), button.getPrimaryColor().getB()};

       if(button.isRounded() == false)
       {
            drawBox(canvas, startX, startY, box);
       }
       else
       {    
            drawRoundedBox(canvas, startX, startY, box);
       }

       if(button.isTextCentered() == false)
       {
        drawText(canvas, startX + horizontal_padding * button.getWidth(), startY + box.getHeight() / 2 - text.getHeight() / 2, text);
       }
       else
       {
        drawText(canvas, startX + button.getWidth() / 2 - text.getWidth() / 2, startY + box.getHeight() / 2 - text.getHeight() / 2, text);
       }

}
