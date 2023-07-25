#include "../headers/utils.h"
#include "../headers/Box.h"
#include "../headers/Text.h"
#include "../headers/Button.h"
#include "../headers/TextBox.h"
#include "../headers/Captcha.h"
#include "../headers/Layout.h"
#include "../headers/Color.h"

#include "../headers/CImg.h"

#include "../rapidjson/document.h"
#include "../rapidjson/filereadstream.h"

#include <random>
#include <iostream>
#include <fstream>
#include <cstdlib>

int utils::randomInt(int min, int max)
{
     std::random_device rd;
     std::uniform_real_distribution<double> dist(0.0, 1.0);

     int output = min + (max - min) * dist(rd);
    
    return output;
}
int utils::randomThickness(int min, int max)
{
    int hasThickness = randomInt(0, 100);

    if(hasThickness > 50)
    {
        return randomInt(0, 100);
    }

    return 0;
}
Color utils::randomColor()
{
    int r = randomInt(0, 255);
    int g = randomInt(0, 255);
    int b = randomInt(0, 255);
    int a = 1;

    Color output(r, g, b, a);

    return output;
}
std::string utils::randomString()
{
    std::string alphabet[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    int continueString = randomInt(0, 100);

    std::string output = "";
    
    while(continueString > 5)
    {

        if(continueString > 5)
        {
            int letterIndex = randomInt(0, 25);

            output += alphabet[letterIndex];
        }

        continueString = randomInt(0, 100);

    }

    return output;
}
bool utils::randomBool()
{
    int randomBool  = randomInt(0, 100);

    if(randomBool > 50)
    {
        return true;
    }
    else
    {
        return false;
    }
}

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

        if(box.getPrimaryColor().getA() > 0)
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

       Box box = Box("random_element", button.getWidth(), button.getHeight(), button.getPrimaryColor(), button.getBorderThickness(), button.getBoxOutlineColor());

       Text text = Text("random_element", button.getTextFontSize(), button.getText(), button.getTextColor());

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

    Box box("random_element", radioBox.getWidth(), radioBox.getHeight(), radioBox.getPrimaryColor(), radioBox.getBorderThickness(), radioBox.getBoxOutlineColor());

    Text radioOptionText = Text("random_element", radioBox.getTextFontSize(), radioBox.getText(), radioBox.getTextColor());

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
    canvas.draw_circle(startX + leftPadding, startY + radioBox.getHeight() / 2, circleRadius, circleOutlineColor, 1);
    canvas.draw_circle(startX + leftPadding, startY + radioBox.getHeight() / 2, circleRadius * 0.75, circleFillColor, 1);
    
    
}
void utils::drawTextBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, TextBox box)
{
    Button button("random_element", box.getWidth(), box.getHeight(), box.getHintText(), box.getTextFontSize(), box.getTextColor(), box.getPrimaryColor(), box.getBorderThickness(), box.getBoxOutlineColor(), box.isRounded(), box.isTextCentered());

    Text buttonText = Text("random_element", button.getTextFontSize(), button.getText(), button.getTextColor());

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
    
    Box containerBox("random_element", checkBox.getWidth(), checkBox.getHeight(), checkBox.getContainerFillColor(), checkBox.getBorderThickness(), checkBox.getContainerOutlineColor());
    
    float checkmarkBoxWidth = 0.3 * containerBox.getHeight();
    
    Box checkMarkBox("checkmark", checkmarkBoxWidth, checkmarkBoxWidth, checkBox.getCheckmarkBoxFillColor(),  checkmarkBoxWidth * 0.2, checkBox.getCheckmarkBoxOutlineColor());

    Text checkmarkOptionText = Text("random_element", checkBox.getTextFontSize(), checkBox.getText(), checkBox.getTextColor());

    if(checkBox.isContainerRounded())
    {
        drawRoundedBox(canvas, startX, startY, containerBox);
    }
    else
    {
        drawBox(canvas, startX, startY, containerBox);
    }

    if(checkBox.isCheckmarkBoxRounded())
    {
        drawRoundedBox(canvas, startX + checkmarkBoxWidth, startY + containerBox.getHeight() / 2 - checkmarkBoxWidth / 2, checkMarkBox);
    }
    else
    {
        drawBox(canvas, startX + checkmarkBoxWidth, startY + containerBox.getHeight() / 2  - checkmarkBoxWidth / 2, checkMarkBox);
    }

    //text not horizontally centered
    if(checkBox.isTextCentered() == false)
    {
        drawText(canvas, startX + checkmarkBoxWidth * 3, startY + containerBox.getHeight() / 2 - checkmarkOptionText.getHeight() / 2, checkmarkOptionText);
    }
    //text horizontally centered
    else if(checkBox.isTextCentered() == true)
    {
        drawText(canvas, startX + checkBox.getWidth() / 2 - checkmarkOptionText.getWidth() / 2, startY + containerBox.getHeight() / 2 - checkmarkOptionText.getHeight() / 2, checkmarkOptionText);
    }
}
void utils::drawImagePlaceholder(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, ImagePlaceholder imagePlaceHolder)
{
    int counter = 0;

    for(int i = 0; i < imagePlaceHolder.getWidth(); i=i+3)
    {
        const unsigned char black[] = {0, 0, 0};
        const unsigned char white[] = {255, 255, 255};

        if(counter % 2 == 0)
        {
            canvas.draw_rectangle(startX + i, startY, startX + i + 3, startY + imagePlaceHolder.getHeight(), black);
        }
        else
        {
            canvas.draw_rectangle(startX + i, startY, startX + i + 3, startY + imagePlaceHolder.getHeight(), white);
        }

        counter++;
    }
}
void utils::drawCaptcha(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Captcha captcha)
{
    cimg_library::CImg<unsigned char> src("recaptcha.bmp");
    src.resize(captcha.getWidth(), captcha.getWidth() * 0.25);
    canvas.draw_image(startX, startY, src);
}

void utils::drawLayout(Layout layout, std::string filename)
{
    //element ids
    //0 - box
    //1 - text
    //2 - textbox
    //3 - button
    //4 - checkmark
    //5 - radio option
    //6 - captcha
    //7 image place holder

    unsigned int canvasWidth = 1920;
    unsigned int canvasHeight = 1080;

    cimg_library::CImg<unsigned char> bg(canvasWidth,canvasHeight,1,3, 255);

    while(layout.numElements() > 0)
    { 
        int lowestIndexType = 8;
        int currentLowestIndex = -1;

        if(layout.numBoxElements() > 0)
        {
            if(layout.getBox(0).getIndex () < currentLowestIndex || currentLowestIndex < 0)
            {
                lowestIndexType = 0;
                currentLowestIndex = layout.getBox(0).getIndex();
            }
        }

        if(layout.numTextElements() > 0)
        {
            if(layout.getTextElement(0).getIndex () < currentLowestIndex || currentLowestIndex < 0)
            {   

                lowestIndexType = 1;
                currentLowestIndex = layout.getTextElement(0).getIndex();
            }
        }

        if(layout.numButtonElements() > 0)
        {
            if(layout.getButtonElement(0).getIndex () < currentLowestIndex || currentLowestIndex < 0)
            {
                lowestIndexType = 3;
                currentLowestIndex = layout.getButtonElement(0).getIndex();
            }
        }

        if(layout.numTextBoxElements() > 0)
        {
            if(layout.getTextBoxElement(0).getIndex () < currentLowestIndex || currentLowestIndex < 0)
            {
                lowestIndexType = 2;
                currentLowestIndex = layout.getTextBoxElement(0).getIndex();
            }
        }

        if(layout.numCheckmarkElements() > 0)
        {
            if(layout.getCheckmarkElement(0).getIndex () < currentLowestIndex || currentLowestIndex < 0)
            {
                lowestIndexType = 4;
                currentLowestIndex = layout.getCheckmarkElement(0).getIndex();
            }
        }

        if(layout.numRadioOptionElements() > 0)
        {
            if(layout.getRadioOptionElement(0).getIndex () < currentLowestIndex || currentLowestIndex < 0)
            {
                lowestIndexType = 5;
                currentLowestIndex = layout.getRadioOptionElement(0).getIndex();
            }
        }

        if(layout.numCaptchaElements() > 0)
        {
            if(layout.getCaptchaElement(0).getIndex () < currentLowestIndex || currentLowestIndex < 0)
            {
                lowestIndexType = 6;
                currentLowestIndex = layout.getCaptchaElement(0).getIndex();
                
            }
        }

        if(layout.numImagePlaceHolderElements() > 0)
        {
            if(layout.getImagePlaceHolderElement(0).getIndex () < currentLowestIndex || currentLowestIndex < 0)
            {
                lowestIndexType = 7;
                currentLowestIndex = layout.getImagePlaceHolderElement(0).getIndex();
                
            }
        }

        if(lowestIndexType == 0)
        {
            Box box = layout.getBox(0);
            drawBox(bg, layout.getXCoordinate(0), layout.getYCoordinate(0), box);
            layout.popBox();

        }
        else if(lowestIndexType == 1)
        {
            Text text = layout.getTextElement(0);
            drawText(bg, layout.getXCoordinate(0), layout.getYCoordinate(0), text);
            layout.popTextElement();
        }
        else if(lowestIndexType == 3)
        {
            Button button = layout.getButtonElement(0);
            drawButton(bg, layout.getXCoordinate(0), layout.getYCoordinate(0), button);
            layout.popButtonElement();
        }
        else if(lowestIndexType == 2)
        {
            TextBox textBox = layout.getTextBoxElement(0);
            drawTextBox(bg, layout.getXCoordinate(0), layout.getYCoordinate(0), textBox);
            layout.popTextBoxElement();
        }
        else if(lowestIndexType == 4)
        {
            CheckMark checkMark = layout.getCheckmarkElement(0);
            drawCheckBox(bg, layout.getXCoordinate(0), layout.getYCoordinate(0), checkMark);
            layout.popCheckmarkElement();
        }

        else if(lowestIndexType == 5)
        {
            RadioOption radioOption = layout.getRadioOptionElement(0);
            drawRadioOption(bg, layout.getXCoordinate(0), layout.getYCoordinate(0), radioOption);
            layout.popRadioOptionElement();
        }

        else if(lowestIndexType == 6)
        {
            Captcha captcha = layout.getCaptchaElement(0);
            drawCaptcha(bg, layout.getXCoordinate(0), layout.getYCoordinate(0), captcha);
            layout.popCaptchaElement();
        }

        else if(lowestIndexType == 7)
        {
            ImagePlaceholder imagePlaceholder = layout.getImagePlaceHolderElement(0);
            drawImagePlaceholder(bg, layout.getXCoordinate(0), layout.getYCoordinate(0), imagePlaceholder);
            layout.popImagePlaceHolderElement();
        }
        
        layout.popXCoordinate();
        layout.popYCoordinate();
    }

    bg.save((filename + ".bmp").c_str());
}

Box utils::randomBox(int maxWidth, int maxHeight)
{
   
    int randomWidth =  randomInt(0, maxWidth);
    int randomHeight =  randomInt(0, maxHeight);

    int randThick = randomThickness(0, maxWidth);

    Box box("random_element", randomWidth, randomHeight, randomColor(), randThick, randomColor());

    return box;
}
Text utils::randomText()
{
    int fontSize = randomInt(5, 200);
    Color randomTextColor = randomColor();
    std::string randomText = randomString();

    Text text("random_element", fontSize, "test", randomTextColor);

    return text;
}
Button utils::randomButton(int maxWidth, int maxHeight)
{
    //Button(int w, int h, std::string text, int textFontSize, Color textColor, Color primaryColor, int borderThickness, Color boxOutlineColor, bool buttonRounded, bool buttonTextCentered)

    int randomWidth =  randomInt(0, maxWidth);
    int randomHeight =  randomInt(0, maxHeight);

    int randThick = randomThickness(0, maxWidth);

    int fontSize = randomInt(5, 200);
    std::string randomText = randomString();

    Button button("random_element", randomWidth, randomHeight, randomText, fontSize, randomColor(), randomColor(), randThick, randomColor(), randomBool(), randomBool());

    return button;

}
TextBox utils::randomTextBox(int maxWidth, int maxHeight)
{
    //int w, int h, std::string hintText, int textFontSize, int borderThickness, Color hintTextColor, Color boxFillColor, Color boxOutlineColor, Color underLineColor, bool textBoxRounded, bool textboxTextCentered, bool hasUnderLine)
    int randomWidth =  randomInt(0, maxWidth);
    int randomHeight =  randomInt(0, maxHeight);

    int fontSize = randomInt(5, 200);
    int randThick = randomThickness(0, maxWidth);
    
    std::string randomHintText = randomString();

    TextBox textBox("random_element", randomWidth, randomHeight, randomHintText, fontSize, randThick, randomColor(), randomColor(), randomColor(), randomColor(), randomBool(), randomBool(), randomBool());

    return textBox;
}
CheckMark utils::randomCheckBox(int maxWidth, int maxHeight)
{
    //CheckMark::CheckMark(int w, int h, std::string text, int textFontSize, Color textColor, Color checkmarkBoxFillColor, Color checkmarkBoxOutlineColor, Color containerFillColor, Color containerOutlineColor, int borderThickness, bool containerRounded, bool buttonTextCentered, bool checkMarkBoxRounded)

    int randomWidth =  randomInt(0, maxWidth);
    int randomHeight =  randomInt(0, maxHeight);

    std::string randomCheckmarkText = randomString();

    int randThick = randomThickness(0, maxWidth);

    int fontSize = randomInt(5, 200);

    CheckMark randomCheckmark("random_element", randomWidth, randomHeight,  randomCheckmarkText, fontSize, randomColor(), randomColor(), randomColor(), randomColor(), randomColor(), randThick, randomBool(), randomBool(), randomBool());

    return randomCheckmark;
}
RadioOption utils::randomRadioOption(int maxWidth, int maxHeight)
{
    //RadioOption(int w, int h, std::string text, int textFontSize, Color textColor, Color boxFillColor, Color circleFillColor, Color circleOutlineColor, int borderThickness, Color boxOutlineColor, bool buttonRounded, bool buttonTextCentered);
    int randomWidth =  randomInt(0, maxWidth);
    int randomHeight =  randomInt(0, maxHeight);

    int fontSize = randomInt(5, 200);

    std::string randomText = randomString();
    int randThick = randomThickness(0, maxWidth);

    RadioOption radioOption("random_element", randomWidth, randomHeight, randomText, fontSize, randomColor(), randomColor(), randomColor(), randomColor(), randThick, randomColor(), randomBool(), randomBool());

    return radioOption;

}
ImagePlaceholder utils::randomImagePlaceholder(int maxWidth, int maxHeight)
{
    int randomWidth =  randomInt(0, maxWidth);
    int randomHeight =  randomInt(0, maxHeight);

    ImagePlaceholder imagePlaceholder("random_element", randomWidth, randomHeight);
    return imagePlaceholder;
}
Captcha utils::randomCaptcha(int maxWidth)
{
    int randomWidth =  randomInt(0, maxWidth);
   

    Captcha captcha("random_element", randomWidth);
    return captcha;
}

rapidjson::Document utils::loadJson(std::string jsonPath)
{
    std::ifstream file(jsonPath);

    std::string jsonContent((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return NULL;
    }

    file.close();

    rapidjson::Document document;
    document.Parse(jsonContent.c_str());

    if (document.HasParseError()) {
        std::cout << "Failed to parse JSON." << std::endl;
        return NULL;
    }

    return document;
}

int utils::mutateInt(int original, int max)
{
   bool addOrSubtract = randomBool();
   bool doNothing = randomBool();

   if(doNothing == false)
   {

    //add
    if(addOrSubtract)
    {
        if(original < max) return (original + 1);

        return original;
    }
    else
    {
        if(original > 0) return (original - 1);

        return 0;
    }

   }

   return original;
}

//creates a layout object from a json file
Layout utils::getLayout(std::string jsonPath)
{
    Layout layout;

    rapidjson::Document currentDocument = loadJson(jsonPath);

      for (rapidjson::SizeType i = 0; i < currentDocument.Size(); ++i) 
      {
        rapidjson::Value& object = currentDocument[i];

        std::string id;
        std::string type;

        int startingX = 0;
        int startingY = 0;

        if (object.HasMember("type") && object["type"].IsString()) {
            type = object["type"].GetString();
        }

        if (object.HasMember("drawX") && object["drawX"].IsInt()) {
            startingX = object["drawX"].GetInt();
        }

        if (object.HasMember("drawY") && object["drawY"].IsInt()) {
            startingY = object["drawY"].GetInt();
        }

        layout.addXCoordinate(startingX);
        layout.addYCoordinate(startingY);

        if(type == "Box")
        {
            Box box = parseBox(object, i);
            
            layout.addBox(box);
           
        }

        else if(type == "Text")
        {
            Text text = parseText(object, i);
            
            layout.addTextElement(text);
        }

        else if(type == "Button")
        {
            Button button = parseButton(object, i);
            
            layout.addButtonElement(button);
        }

        else if(type == "TextBox")
        {
            TextBox textBox = parseTextBox(object, i);
            
            layout.addTextBoxElement(textBox);
        }

        else if(type == "CheckMark")
        {
            CheckMark checkMark = parseCheckBox(object, i);
            
            layout.addCheckmarkElement(checkMark);
        }

        else if(type == "RadioOption")
        {
            RadioOption radioOption = parseRadioOption(object, i);
            
            layout.addRadioOptionElement(radioOption);
        }

        else if(type == "ImagePlaceholder")
        {
            ImagePlaceholder imagePlaceHolder = parseImagePlaceholder(object, i);
            
            layout.addImagePlaceHolderElement(imagePlaceHolder);

        }

        else if(type == "Captcha")
        {
            Captcha captcha = parseCaptcha(object, i);
            
            layout.addCaptchaElement(captcha);

        }
      }    

    return layout;
}

Color utils::parseColor(rapidjson::Value& colorArray)
{
    Color outputColor;

      if (colorArray.Size() == 4 && colorArray[0].IsInt() && colorArray[1].IsInt() && colorArray[2].IsInt() && colorArray[3].IsInt()) {
            int r = colorArray[0].GetInt();
            int g = colorArray[1].GetInt();
            int b = colorArray[2].GetInt();
            int a = colorArray[3].GetInt();

            outputColor = Color(r, g, b, a);
      }

      return outputColor;
}

Box utils::parseBox(rapidjson::Value& object, int index)
{
    /* example
    {

	"id": "element3",
	"type": "Box",
	"drawX": 100,
	"drawY": 50,
	"width": 500,
	"height": 200,
	"primaryColor": [100,0,100,0],
	"borderThickness": 0,
	"boxOutlineColor": [0,128,128,0]
	

    }
    */

    std::string id = "";
    int width = -1;
    int height = -1;

    Color primaryColor;
    Color boxOutlineColor;

    int borderThickness = -1;

    if (object.HasMember("id") && object["id"].IsString()) {
        id = object["id"].GetString();
    }

    if (object.HasMember("width") && object["width"].IsInt()) {
        width = object["width"].GetInt();
    }

    if (object.HasMember("height") && object["height"].IsInt()) {
        height = object["height"].GetInt();
    }

    if (object.HasMember("primaryColor") && object["primaryColor"].IsArray()) {
        
        rapidjson::Value& colorArray = object["primaryColor"];

        primaryColor = parseColor(colorArray);
    }

    if (object.HasMember("boxOutlineColor") && object["boxOutlineColor"].IsArray()) {
        
        rapidjson::Value& colorArray = object["boxOutlineColor"];

        boxOutlineColor = parseColor(colorArray);
    }

    if (object.HasMember("borderThickness")) {
        
        borderThickness = object["borderThickness"].GetInt();
    }

    Box outputBox(id, width, height, primaryColor, borderThickness, boxOutlineColor);
    outputBox.setIndex(index);

    return outputBox;
}

Text utils::parseText(rapidjson::Value& object, int index)
{
    /*
    {

	"id": "element3",
	"type": "Text",
	"drawX": 100,
	"drawY": 50,
	"textSize": 20,
	"textColor": [100,0,100,0],
	
    }
    */

    std::string id = "";
    std::string text = "";

    int fontSize = 0;

    Color textColor;

    int borderThickness = -1;

    if (object.HasMember("id") && object["id"].IsString()) {
        id = object["id"].GetString();
    }

    if (object.HasMember("text") && object["text"].IsString()) {
        text = object["text"].GetString();
    }

    if (object.HasMember("textSize") && object["textSize"].IsInt()) {
        fontSize = object["textSize"].GetInt();
    }

    if (object.HasMember("textColor") && object["textColor"].IsArray()) {
        
        rapidjson::Value& colorArray = object["textColor"];

        textColor = parseColor(colorArray);
    }

    Text outputText(id, fontSize, text, textColor);
    outputText.setIndex(index);
    return outputText;
}

Button utils::parseButton(rapidjson::Value& object, int index)
{
    /* example
    {
	
        "id": "element3",
        "type": "Button",
        "drawX": 100,
        "drawY": 50,
        "width": 100,
        "height": 100,
        "text": "This is a test",
        "textSize": 20,
        "borderThickness": 0,
        "textColor": [100,0,100,0],
        "primaryColor": [100,0,100,0],
        "boxOutlineColor": [0,128,128,0],
        "rounded":true,
        "textCentered":true,
	
    }
    */

    std::string id = "";
    std::string text = "";

    int width = 0;
    int height = 0;
    int fontSize = 0;
    int borderThickness = 0;

    Color primaryColor;
    Color boxOutlineColor;
    Color textColor;

    bool isRounded = false;
    bool textCentered =  false;

    if (object.HasMember("id") && object["id"].IsString()) {
        id = object["id"].GetString();
    }

    if (object.HasMember("text") && object["text"].IsString()) {
        text = object["text"].GetString();
    }

    if (object.HasMember("width") && object["width"].IsInt()) {
        width = object["width"].GetInt();
    }

    if (object.HasMember("height") && object["height"].IsInt()) {
        height = object["height"].GetInt();
    }

    if (object.HasMember("textSize") && object["textSize"].IsInt()) {
        fontSize = object["textSize"].GetInt();
    }

    if (object.HasMember("borderThickness") && object["borderThickness"].IsInt()) {
        borderThickness = object["borderThickness"].GetInt();
    }

    if (object.HasMember("textColor") && object["textColor"].IsArray()) {
       textColor = parseColor(object["textColor"]);
    }

    if (object.HasMember("primaryColor") && object["primaryColor"].IsArray()) {
       primaryColor = parseColor(object["primaryColor"]);
    }

    if (object.HasMember("boxOutlineColor") && object["boxOutlineColor"].IsArray()) {
       boxOutlineColor = parseColor(object["boxOutlineColor"]);
    }

    if (object.HasMember("rounded") && object["rounded"].IsBool()) {
       isRounded = object["rounded"].GetBool();
    }

    if (object.HasMember("textCentered") && object["textCentered"].IsBool()) {
       textCentered = object["textCentered"].GetBool();
    }

    Button outputButton(id, width, height, text, fontSize, textColor, primaryColor, borderThickness, boxOutlineColor, isRounded, textCentered);
    outputButton.setIndex(index);

    return outputButton;
}

TextBox utils::parseTextBox(rapidjson::Value& object, int index)
{
    /* example
    {
	
        "id": "element3",
        "type": "TextBox",
        "drawX": 100,
        "drawY": 50,
        "width": 100,
        "height": 100,
        "text": "This is a test",
        "textSize": 20,
        "borderThickness": 0,
        "textColor": [100,0,100,0],
        "primaryColor": [100,0,100,0],
        "boxOutlineColor": [0,128,128,0],
		"underlineColor": [0, 0, 0, 0],
        "textBoxRounded":true,
        "textCentered":true,
		"hasUnderLine": true,
	
    }
    */
   
    std::string id = "";
    std::string text = "";

    int width = 0;
    int height = 0;
    int fontSize = 0;
    int borderThickness = 0;

    Color primaryColor;
    Color boxOutlineColor;
    Color textColor;
    Color underlineColor;

    bool isRounded = false;
    bool textCentered =  false;
    bool hasUnderline = false;

    if (object.HasMember("id") && object["id"].IsString()) {
        id = object["id"].GetString();
    }

    if (object.HasMember("text") && object["text"].IsString()) {
        text = object["text"].GetString();
    }

    if (object.HasMember("width") && object["width"].IsInt()) {
        width = object["width"].GetInt();
    }

    if (object.HasMember("height") && object["height"].IsInt()) {
        height = object["height"].GetInt();
    }

    if (object.HasMember("textSize") && object["textSize"].IsInt()) {
        fontSize = object["textSize"].GetInt();
    }

    if (object.HasMember("borderThickness") && object["borderThickness"].IsInt()) {
        borderThickness = object["borderThickness"].GetInt();
    }

    if (object.HasMember("textColor") && object["textColor"].IsArray()) {
       textColor = parseColor(object["textColor"]);
    }

    if (object.HasMember("primaryColor") && object["primaryColor"].IsArray()) {
       primaryColor = parseColor(object["primaryColor"]);
    }

    if (object.HasMember("boxOutlineColor") && object["boxOutlineColor"].IsArray()) {
       boxOutlineColor = parseColor(object["boxOutlineColor"]);
    }

    if (object.HasMember("underlineColor") && object["underlineColor"].IsArray()) {
       underlineColor = parseColor(object["underlineColor"]);
    }

    if (object.HasMember("rounded") && object["rounded"].IsBool()) {
       isRounded = object["rounded"].GetBool();
    }

    if (object.HasMember("textCentered") && object["textCentered"].IsBool()) {
       textCentered = object["textCentered"].GetBool();
    }
    
    if (object.HasMember("hasUnderLine") && object["hasUnderLine"].IsBool()) {
       hasUnderline = object["hasUnderLine"].GetBool();
    }

    TextBox outputTextBox(id, width, height, text, fontSize, borderThickness, textColor, primaryColor, boxOutlineColor, underlineColor, isRounded, textCentered, hasUnderline);
    outputTextBox.setIndex(index);

    return outputTextBox;
}

CheckMark utils::parseCheckBox(rapidjson::Value& object, int index)
{
    /* example
    {
	
        "id": "element3",
        "type": "CheckMark",
        "drawX": 100,
        "drawY": 50,
        "width": 100,
        "height": 100,
        "text": "This is a test",
        "textSize": 20,
        "borderThickness": 0,
        "textColor": [100,0,100,0],
        "primaryColor": [100,0,100,0],
		"containerOutlineColor":[100,0,100,0],
        "checkmarkBoxFillColor": [0,128,128,0],
		"checkmarkBoxOutlineColor": [0, 0, 0, 0],
        "containerRounded":true,
        "buttonTextCentered":true,
		"checkMarkBoxRounded": true,
	
    }
    */

    std::string id = "";
    std::string text = "";

    int width = 0;
    int height = 0;
    int fontSize = 0;
    int borderThickness = 0;

    Color primaryColor;
    Color containerOutlineColor;
    Color textColor;
    Color checkmarkBoxFillColor;
    Color checkmarkBoxOutlineColor;

    bool containerRounded = false;
    bool containerTextCentered =  false;
    bool checkMarkBoxRounded = false;

    if (object.HasMember("id") && object["id"].IsString()) {
        id = object["id"].GetString();
    }

    if (object.HasMember("text") && object["text"].IsString()) {
        text = object["text"].GetString();
    }

    if (object.HasMember("width") && object["width"].IsInt()) {
        width = object["width"].GetInt();
    }

    if (object.HasMember("height") && object["height"].IsInt()) {
        height = object["height"].GetInt();
    }

    if (object.HasMember("textSize") && object["textSize"].IsInt()) {
        fontSize = object["textSize"].GetInt();
    }

    if (object.HasMember("borderThickness") && object["borderThickness"].IsInt()) {
        borderThickness = object["borderThickness"].GetInt();
    }

    if (object.HasMember("textColor") && object["textColor"].IsArray()) {
       textColor = parseColor(object["textColor"]);
    }

    if (object.HasMember("primaryColor") && object["primaryColor"].IsArray()) {
       primaryColor = parseColor(object["primaryColor"]);
    }

    if (object.HasMember("containerOutlineColor") && object["containerOutlineColor"].IsArray()) {
       containerOutlineColor = parseColor(object["containerOutlineColor"]);
    }

    if (object.HasMember("checkmarkBoxFillColor") && object["checkmarkBoxFillColor"].IsArray()) {
       checkmarkBoxFillColor = parseColor(object["checkmarkBoxFillColor"]);
    }

    if (object.HasMember("checkmarkBoxOutlineColor") && object["checkmarkBoxOutlineColor"].IsArray()) {
       checkmarkBoxOutlineColor = parseColor(object["checkmarkBoxOutlineColor"]);
    }

    if (object.HasMember("containerRounded") && object["containerRounded"].IsBool()) {
       containerRounded = object["containerRounded"].GetBool();
    }

    if (object.HasMember("containerTextCentered") && object["containerTextCentered"].IsBool()) {
       containerTextCentered = object["containerTextCentered"].GetBool();
    }
    
    if (object.HasMember("checkMarkBoxRounded") && object["checkMarkBoxRounded"].IsBool()) {
       checkMarkBoxRounded = object["checkMarkBoxRounded"].GetBool();
    }

    CheckMark outputCheckMark(id, width, height, text, fontSize, textColor, checkmarkBoxFillColor, checkmarkBoxOutlineColor, primaryColor, containerOutlineColor, 
    borderThickness, containerRounded, containerTextCentered, checkMarkBoxRounded);
    
    outputCheckMark.setIndex(index);

    return outputCheckMark;
}


RadioOption utils::parseRadioOption(rapidjson::Value& object, int index)
{
    /* example
    {
	
        "id": "element3",
        "type": "RadioOption",
        "drawX": 100,
        "drawY": 50,
        "width": 100,
        "height": 100,
        "text": "This is a test",
        "textSize": 20,
        "borderThickness": 0,
        "textColor": [100,0,100,0],
        "primaryColor": [100,0,100,0],
		"boxOutlineColor":[100,0,100,0],
        "circleFillColor": [0,128,128,0],
		"circleOutlineColor": [0, 0, 0, 0],
        "containerRounded":true,
        "containerTextCentered":true	
    }
    */

    std::string id = "";
    std::string text = "";

    int width = 0;
    int height = 0;
    int fontSize = 0;
    int borderThickness = 0;

    Color textColor;
    Color primaryColor;
    Color boxOutlineColor;
    Color circleFillColor;
    Color circleOutlineColor;

    bool containerRounded = false;
    bool containerTextCentered =  false;
    bool checkMarkBoxRounded = false;

    if (object.HasMember("id") && object["id"].IsString()) {
        id = object["id"].GetString();
    }

    if (object.HasMember("text") && object["text"].IsString()) {
        text = object["text"].GetString();
    }

    if (object.HasMember("width") && object["width"].IsInt()) {
        width = object["width"].GetInt();
    }

    if (object.HasMember("height") && object["height"].IsInt()) {
        height = object["height"].GetInt();
    }

    if (object.HasMember("textSize") && object["textSize"].IsInt()) {
        fontSize = object["textSize"].GetInt();
    }

    if (object.HasMember("borderThickness") && object["borderThickness"].IsInt()) {
        borderThickness = object["borderThickness"].GetInt();
    }

    if (object.HasMember("textColor") && object["textColor"].IsArray()) {
       textColor = parseColor(object["textColor"]);
    }

    if (object.HasMember("primaryColor") && object["primaryColor"].IsArray()) {
       primaryColor = parseColor(object["primaryColor"]);
    }

    if (object.HasMember("boxOutlineColor") && object["boxOutlineColor"].IsArray()) {
       boxOutlineColor = parseColor(object["boxOutlineColor"]);
    }

    if (object.HasMember("circleFillColor") && object["circleFillColor"].IsArray()) {
       circleFillColor = parseColor(object["circleFillColor"]);
    }

    if (object.HasMember("circleOutlineColor") && object["circleOutlineColor"].IsArray()) {
       circleOutlineColor = parseColor(object["circleOutlineColor"]);
    }

    if (object.HasMember("containerRounded") && object["containerRounded"].IsBool()) {
       containerRounded = object["containerRounded"].GetBool();
    }

    if (object.HasMember("containerTextCentered") && object["containerTextCentered"].IsBool()) {
       containerTextCentered = object["containerTextCentered"].GetBool();
    }
    
    RadioOption outputRadioOption(id, width, height, text, fontSize, textColor, primaryColor, circleFillColor, circleOutlineColor, borderThickness, boxOutlineColor, containerRounded, containerTextCentered);
    
    outputRadioOption.setIndex(index);

    return outputRadioOption;
}

ImagePlaceholder utils::parseImagePlaceholder(rapidjson::Value& object, int index)
{
    /* example
    {
	
        "id": "element3",
        "type": "ImagePlaceholder",
        "drawX": 100,
        "drawY": 50,
        "width": 100,
        "height": 100,	
    }
    */

    std::string id = "";
    std::string text = "";

    int width = 0;
    int height = 0;

    if (object.HasMember("id") && object["id"].IsString()) {
        id = object["id"].GetString();
    }

    if (object.HasMember("width") && object["width"].IsInt()) {
        width = object["width"].GetInt();
    }

    if (object.HasMember("height") && object["height"].IsInt()) {
        height = object["height"].GetInt();
    }

    ImagePlaceholder imagePlaceholder(id, width, height);

    imagePlaceholder.setIndex(index);

    return imagePlaceholder;
}

Captcha utils::parseCaptcha(rapidjson::Value& object, int index)
{
    /* example
    {
	
        "id": "element3",
        "type": "Captcha",
        "drawX": 100,
        "drawY": 50,
        "width": 100
    }
    */

    std::string id = "";
    std::string text = "";

    int width = 0;
    int height = 0;

    if (object.HasMember("id") && object["id"].IsString()) {
        id = object["id"].GetString();
    }

    if (object.HasMember("width") && object["width"].IsInt()) {
        width = object["width"].GetInt();
    }

    Captcha captcha(id, width);

    captcha.setIndex(index);

    return captcha;
}