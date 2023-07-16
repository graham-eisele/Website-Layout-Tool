#include "CIMG.h"
#include "Box.h"
#include "Text.h"
#include "TextBox.h"
#include "CheckMark.h"
#include "Button.h"
#include "RadioOption.h"

class utils
{
public:

     static void drawBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Box box);
     static void drawText(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Text text);
     static void drawButton(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Button button);
     static void drawRoundedBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Box box);
     static void drawRadioOption(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, RadioOption box);
     static void drawTextBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, TextBox box);
     static void drawCheckBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, CheckMark checkBox);
     
 
private:

   
};
