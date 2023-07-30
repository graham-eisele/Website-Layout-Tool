#include "../headers/Layout.h"
#include <iostream>

#include "../headers/Box.h"
#include "../headers/Text.h"
#include "../headers/TextBox.h"
#include "../headers/Button.h"
#include "../headers/CheckMark.h"
#include "../headers/RadioOption.h"
#include "../headers/Captcha.h"

void Layout::addBox(Box box)
{
    boxElements.push_back(box);
}
void Layout::addTextElement(Text text)
{
    textElements.push_back(text);
}
void Layout::addTextBoxElement(TextBox textBox)
{
    textboxElements.push_back(textBox);
}
void Layout::addButtonElement(Button button)
{
    buttonElements.push_back(button);
}
void Layout::addCheckmarkElement(CheckMark checkmark)
{
    checkmarkElements.push_back(checkmark);
}
void Layout::addRadioOptionElement(RadioOption radioOption)
{
    radioOptionElements.push_back(radioOption);
}
void Layout::addCaptchaElement(Captcha captcha)
{
    captchaElements.push_back(captcha);
}
void Layout::addImagePlaceHolderElement(ImagePlaceholder imagePlaceholder)
{
    imagePlaceholderElements.push_back(imagePlaceholder);
}

void Layout::setCanvasWidth(int width)
{
    this->canvasWidth = width;
}

void Layout::setCanvasHeight(int height)
{
    this->canvasHeight = height;
}

Box Layout::popBox()
{
    Box outputBox("null", 0, 0, Color(0, 0, 0, 0), 0, Color(0, 0, 0, 0), false);

    if(numBoxElements() > 0)
    {
        outputBox = boxElements[0];
        boxElements.pop_front();
        return outputBox;
    }

    return outputBox;
}
Text Layout::popTextElement()
{
    Text outputText("null", 0, "", Color(0, 0, 0, 0));

    if(numTextElements() > 0)
    {
        outputText = textElements[0];
        textElements.pop_front();
        return outputText;
    }

    return outputText;
}
TextBox Layout::popTextBoxElement()
{
    TextBox front = textboxElements[0];
    textboxElements.pop_front();
    return front;
}
Button Layout::popButtonElement()
{
    Button outputButton("null", 0, 0, "", 0, Color(0, 0, 0, 0), Color(0, 0, 0, 0), 0, Color(0, 0, 0, 0), false, false);

    if(numButtonElements() > 0)
    {
        outputButton = buttonElements[0];
        buttonElements.pop_front();
        return outputButton;
    }

    return outputButton;
}
CheckMark Layout::popCheckmarkElement()
{
    CheckMark front = checkmarkElements[0];
    checkmarkElements.pop_front();
    return front;
}
RadioOption Layout::popRadioOptionElement()
{
    RadioOption front = radioOptionElements[0];
    radioOptionElements.pop_front();
    return front;
}
Captcha Layout::popCaptchaElement()
{
    Captcha front = captchaElements[0];
    captchaElements.pop_front();
    return front;
}
ImagePlaceholder Layout::popImagePlaceHolderElement()
{
    ImagePlaceholder front = imagePlaceholderElements[0];
    imagePlaceholderElements.pop_front();
    return front;
}

int Layout::numElements()
{
    int numElements = 0;

    numElements =  numBoxElements() + numTextElements() + numTextBoxElements() + numButtonElements() +
    numCheckmarkElements() + numRadioOptionElements() + numCaptchaElements() + numImagePlaceHolderElements();

    return numElements;

}

int Layout::numBoxElements()
{
    return boxElements.size();
}
int Layout::numTextElements()
{
    return textElements.size();
}
int Layout::numTextBoxElements()
{
    return textboxElements.size();
}
int Layout::numButtonElements()
{
    return buttonElements.size();
}
int Layout::numCheckmarkElements()

{
  
    return checkmarkElements.size();
}
int Layout::numRadioOptionElements()
{
    return radioOptionElements.size();
}
int Layout::numCaptchaElements()
{
    return captchaElements.size();
}
int Layout::numImagePlaceHolderElements()
{
    return imagePlaceholderElements.size();
}
int Layout::numXCoordinates()
{
    return coordinatesX.size();
}
int Layout::numYCoordinates()
{
    return coordinatesY.size();
}

void Layout::addXCoordinate(int x)
{
    coordinatesX.push_back(x); 
}
void Layout::addYCoordinate(int y)
{
    coordinatesY.push_back(y);
}

Box Layout::getBox(int index)
{
    if(index > numBoxElements())
    {
        std::cout << "Warning. Index is out of range\n";
    }

    Box outputBox = boxElements[index];
    return outputBox;
}
Text Layout::getTextElement(int index)
{
    Text front = textElements[index];
    return front;
}
TextBox Layout::getTextBoxElement(int index)
{
    TextBox front = textboxElements[index];
    return front;
}
Button Layout::getButtonElement(int index)
{
    Button front = buttonElements[index];
    return front;
}
CheckMark Layout::getCheckmarkElement(int index)
{
    CheckMark front = checkmarkElements[index];
    return front;
}
RadioOption Layout::getRadioOptionElement(int index)
{
    RadioOption front = radioOptionElements[index];
    return front;
}
Captcha Layout::getCaptchaElement(int index)
{
    Captcha front = captchaElements[index];
    return front;
}
ImagePlaceholder Layout::getImagePlaceHolderElement(int index)
{
    ImagePlaceholder front = imagePlaceholderElements[index];
    return front;
}

int Layout::getXCoordinate(int index)
{
    return coordinatesX[index];
}
int Layout::getYCoordinate(int index)
{
    return coordinatesY[index];
}

int Layout::popXCoordinate()
{
    int frontXCoordinate = coordinatesX[0];
    coordinatesX.pop_front();
    return frontXCoordinate;
}
int Layout::popYCoordinate()
{
    int frontYCoordinate = coordinatesY[0];
    coordinatesY.pop_front();
    return frontYCoordinate;
}

void Layout::mutate()
{
    for(Box &box: boxElements)
    {
        box.mutate();
    }

    for(Text &text: textElements)
    {
        text.mutate();
    }

    for(TextBox &textBox: textboxElements)
    {
        textBox.mutate();
    }

    for(Button &button: buttonElements)
    {
        button.mutate();
    }

    for(CheckMark &checkMark: checkmarkElements)
    {
        checkMark.mutate();
    }

    for(RadioOption &radioOption: radioOptionElements)
    {
        radioOption.mutate();
    }

    for(Captcha &captcha: captchaElements)
    {
        captcha.mutate();
    }

    for(ImagePlaceholder &imagePlaceHolder: imagePlaceholderElements)
    {
        imagePlaceHolder.mutate();
    }
}