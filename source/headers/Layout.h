#ifndef LAYOUT_H
#define LAYOUT_H
#include "Color.h"
#include "../headers/Layout.h"
#include <iostream>
#include <deque>

#include "Box.h"
#include "Text.h"
#include "TextBox.h"
#include "CheckMark.h"
#include "Button.h"
#include "RadioOption.h"
#include "ImagePlaceholder.h"
#include "Captcha.h"

class Layout
{
    public:

        void addBox(Box box);
        void addTextElement(Text text);
        void addTextBoxElement(TextBox textBox);
        void addButtonElement(Button button);
        void addCheckmarkElement(CheckMark checkmark);
        void addRadioOptionElement(RadioOption radioOption);
        void addCaptchaElement(Captcha captcha);
        void addImagePlaceHolderElement(ImagePlaceholder imagePlaceholder);

        int numElements();
        int numBoxElements();
        int numTextElements();
        int numTextBoxElements();
        int numButtonElements();
        int numCheckmarkElements();
        int numRadioOptionElements();
        int numCaptchaElements();
        int numImagePlaceHolderElements();
        int numXCoordinates();
        int numYCoordinates();

        void setCanvasWidth(int width);
        void setCanvasHeight(int height);

        Box popBox();
        Text popTextElement();
        TextBox popTextBoxElement();
        Button popButtonElement();
        CheckMark popCheckmarkElement();
        RadioOption popRadioOptionElement();
        Captcha popCaptchaElement();
        ImagePlaceholder popImagePlaceHolderElement();

        void addXCoordinate(int x);
        void addYCoordinate(int y);

        int getXCoordinate(int index);
        int getYCoordinate(int index);

        int popXCoordinate();
        int popYCoordinate();

        int getCanvasWidth();
        int getCanvasHeight();

        Box getBox(int index);
        Text getTextElement(int index);
        TextBox getTextBoxElement(int index);
        Button getButtonElement(int index);
        CheckMark getCheckmarkElement(int index);
        RadioOption getRadioOptionElement(int index);
        Captcha getCaptchaElement(int index);        
        ImagePlaceholder getImagePlaceHolderElement(int index);

        void mutate();

    private:
        
        std::deque<Box> boxElements;
        std::deque<Text> textElements;
        std::deque<TextBox> textboxElements;
        std::deque<Button> buttonElements;
        std::deque<CheckMark> checkmarkElements;
        std::deque<RadioOption> radioOptionElements;
        std::deque<Captcha> captchaElements;
        std::deque<ImagePlaceholder> imagePlaceholderElements;

        std::deque<int> coordinatesX;
        std::deque<int> coordinatesY;   

        int canvasWidth;
        int canvasHeight;     
        
        //element ids
        //0 - box
        //1 - text
        //2 - textbox
        //3 - button
        //4 - checkmark
        //5 - radio option
        //6 - captcha
        //7 image place holder

        

    
};
#endif