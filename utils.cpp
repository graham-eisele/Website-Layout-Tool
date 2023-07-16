#include "utils.h"
#include "Box.h"
#include "Text.h"
#include "Button.h"
#include "TextBox.h"
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

    float circle_radius = 0.15 * elementHeight;

    if(borderThickness <= 0 && box.getPrimaryColor().getA() != 0)
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
       

        //radius for the corner circles of the inside rectangle
        float circle_outline_radius = (box.getWidth() - box.getBorderThickness()) / (box.getWidth());

        std::cout << "test1: " << box.getBoxOutlineColor().getA() << std::endl;

        if(box.getBoxOutlineColor().getA() != 0)
        {

            
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

        }


        /***/

        if(box.getPrimaryColor().getA() != 0)
        {
            
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
            canvas.draw_rectangle(startX + borderThickness, startY + circle_radius + borderThickness, startX + elementWidth - borderThickness, startY + elementHeight - circle_radius - borderThickness, boxfillColor, 1);

            //vertical rectangle
            canvas.draw_rectangle(startX + circle_radius + borderThickness, startY + borderThickness, startX + elementWidth - circle_radius - borderThickness, startY + elementHeight - borderThickness, boxfillColor, 1);
        }
    }
    
}

void utils::drawText(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Text text)
{

        if(text.getTextColor().getA() != 0)
        {
  
        const unsigned char textColor[] = {text.getTextColor().getR(), text.getTextColor().getG(), text.getTextColor().getB()};

        canvas.draw_text(startX, startY, text.getText().c_str(), textColor,0,1,text.getFontSize());
        
        }
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

void utils::drawRadioOption(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, RadioOption radioBox)
{
     //as a percentage of the height
    float horizontal_padding = 0.3;

    const unsigned char circleFillColor[] = {radioBox.getCircleFillColor().getR(), radioBox.getCircleFillColor().getG(), radioBox.getCircleFillColor().getB()};
    const unsigned char circleOutlineColor[] = {radioBox.getCircleOutlineColor().getR(), radioBox.getCircleOutlineColor().getG(), radioBox.getCircleOutlineColor().getB()};

    Box box(radioBox.getWidth(), radioBox.getHeight(), radioBox.getPrimaryColor(), radioBox.getBorderThickness(), radioBox.getBoxOutlineColor());

    Text radioOptionText = Text(radioBox.getTextFontSize(), radioBox.getText(), radioBox.getTextColor());

    float circleRadius = 0.15 * box.getHeight();
    float leftPadding = 0.3 * box.getHeight();

    if(radioBox.isRounded())
    {
        drawRoundedBox(canvas, startX, startY, box);
    }
    else
    {
        drawBox(canvas, startX, startY, box);
    }

    //text not horizontally centered
    if(radioBox.isTextCentered() == false)
    {
        drawText(canvas, startX + leftPadding + circleRadius * 2, startY + box.getHeight() / 2 - radioOptionText.getHeight() / 2, radioOptionText);
    }

    //text horizontally centered
    else
    {
        drawText(canvas, startX + radioBox.getWidth() / 2 - radioOptionText.getWidth() / 2, startY + box.getHeight() / 2 - radioOptionText.getHeight() / 2, radioOptionText);
    }

    //option circle and outline if it exists
    canvas.draw_circle(startX + leftPadding, startY + radioBox.getHeight() / 2, circleRadius, circleFillColor, 1);
    canvas.draw_circle(startX + leftPadding, startY + radioBox.getHeight() / 2, circleRadius * 0.75, circleOutlineColor, 1);
    
    
}

void utils::drawTextBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, TextBox box)
{
    Button button(box.getWidth(), box.getHeight(), box.getHintText(), box.getTextFontSize(), box.getTextColor(), box.getPrimaryColor(), box.getBorderThickness(), box.getBoxOutlineColor(), box.isRounded(), box.isTextCentered());

    Text buttonText = Text(button.getTextFontSize(), button.getText(), button.getTextColor());

    drawButton(canvas, startX, startY, button);

    const unsigned char underlineColor[] = {box.getUnderLineColor().getR(), box.getUnderLineColor().getG(), box.getUnderLineColor().getB()};

     //as a percentage of the height
    float horizontal_padding = 0.25;

    if(box.isUnderlined() && box.getUnderLineColor().getA() != 0)
    {
        int underlineBarThickness = 0.1 * buttonText.getHeight();
        float leftPadding = 0.3 * box.getHeight();

        if(button.isTextCentered() == false)
        {
            int underlineStartX = startX + horizontal_padding * button.getWidth();
            int underlineStartY = startY + box.getHeight() / 2 + buttonText.getHeight() / 2;

            canvas.draw_rectangle(underlineStartX, underlineStartY, underlineStartX + buttonText.getWidth(), underlineStartY + underlineBarThickness, underlineColor);
        }
        else    
        {
            int underlineStartX = startX + button.getWidth() / 2 - buttonText.getWidth() / 2;
            int underlineStartY = startY + box.getHeight() / 2 + buttonText.getHeight() / 2;

            canvas.draw_rectangle(underlineStartX, underlineStartY, underlineStartX + buttonText.getWidth(), underlineStartY + underlineBarThickness, underlineColor);
        }
    }  
}

void utils::drawCheckBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, CheckMark checkBox)
{
      //as a percentage of the height
    float horizontal_padding = 0.3;

    const unsigned char checkBoxFillColor[] = {checkBox.getCheckmarkBoxFillColor().getR(), checkBox.getCheckmarkBoxFillColor().getG(), checkBox.getCheckmarkBoxFillColor().getB()};
    const unsigned char checkboxOutlineColor[] = {checkBox.getCheckmarkBoxOutlineColor().getR(), checkBox.getCheckmarkBoxOutlineColor().getG(), checkBox.getCheckmarkBoxOutlineColor().getB()};
    

    Box box(checkBox.getWidth(), checkBox.getHeight(), checkBox.getContainerFillColor(), checkBox.getBorderThickness(), checkBox.getContainerOutlineColor());
    //Box box(100, 100, Color(128, 128, 128, 1), 5, Color(128, 128, 128, 1));

    Text checkmarkOptionText = Text(checkBox.getTextFontSize(), checkBox.getText(), checkBox.getTextColor());

    float checkmarkBoxWidth = 0.3 * box.getHeight();
    float leftPadding = 0.15 * box.getHeight();

    if(checkBox.isRounded())
    {
        drawRoundedBox(canvas, startX, startY, box);
    }
    else
    {
        drawBox(canvas, startX, startY, box);
    }

    //text not horizontally centered
    if(checkBox.isTextCentered() == false)
    {
        drawText(canvas, startX + leftPadding + checkmarkBoxWidth, startY + box.getHeight() / 2 - checkmarkOptionText.getHeight() / 2, checkmarkOptionText);
    }

    //text horizontally centered
    else
    {
        drawText(canvas, startX + checkBox.getWidth() / 2 - checkmarkOptionText.getWidth() / 2, startY + box.getHeight() / 2 - checkmarkOptionText.getHeight() / 2, checkmarkOptionText);
    }

    //canvas.draw_rectangle(startX + leftPadding, startY, startX + leftPadding + checkmarkBoxWidth, startY + checkmarkBoxWidth, checkBoxFillColor, 1);
    //canvas.draw_rectangle(startX + leftPadding, startY, startX + leftPadding + checkmarkBoxWidth * 1.25, startY + checkmarkBoxWidth * 0.75, checkboxOutlineColor, 1);


}
