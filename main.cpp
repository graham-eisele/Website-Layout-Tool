#include <iostream>
#include "utils.h"

#include "Box.h"
#include "Text.h"
#include "Button.h"
#include "RadioOption.h"

#include "CIMG.h"


int main(int argc, const char** argv)
{
    

    unsigned int w = 1920;
    unsigned int h = 1080;

    const unsigned char bluegreen[] = {0, 170, 255};

    cimg_library::CImg<unsigned char> bg(w,h,1,3, 255);

    Color blue(65, 105, 225, 0);

    Box box(300, 500, blue, 50, Color(200, 200, 200, 0));
    Text text(40, "test", blue);

    Button button(400, 200, "test", 40, blue, Color(54, 54, 54, 0), 20, Color(128, 128, 128, 0), true, true);

    RadioOption radioOption(500, 200, "The dog and the cat", 30, Color(255, 255, 255, 1), Color(128, 0, 128, 1), Color(128, 0, 50, 1), Color(0, 0, 0, 1), 6, Color(9,150,140, 1), true, true);
    
    //utils::drawButton(bg, 100, 0, button);
    //utils::drawBox(bg, 0, 0, box);
    //utils::drawText(bg, 0, 0, text);
    utils::drawRadioOption(bg, 0, 0, radioOption);

    bg.save("file.bmp");

    return 0;
}