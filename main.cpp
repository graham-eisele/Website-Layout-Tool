#include <iostream>
#include "utils.h"

#include "Box.h"
#include "Text.h"
#include "Button.h"

#include "CIMG.h"


int main(int argc, const char** argv)
{
    

    unsigned int w = 1920;
    unsigned int h = 1080;

    const unsigned char bluegreen[] = {0, 170, 255};

    cimg_library::CImg<unsigned char> bg(w,h,1,3, 255);

    Color blue(65, 105, 225);

    Box box(300, 500, blue, 100, Color(200, 200, 200));
    Text text(40, "test", blue);

    Button button(200, 200, "test", 40, blue, Color(0, 0, 0), 10, Color(128, 128, 128), false, false);
    
    utils::drawButton(bg, 0, 0, button);
    //utils::drawBox(bg, 0, 0, box);
    //utils::drawText(bg, 0, 0, text);

    bg.save("file.bmp");

    return 0;
}