#include <iostream>
#include "utils.h"

#include "Box.h"
#include "Text.h"
#include "TextBox.h"
#include "Button.h"
#include "CheckMark.h"
#include "RadioOption.h"

#include "CIMG.h"


int main(int argc, const char** argv)
{
    

    unsigned int canvasWidth = 1920;
    unsigned int canvasHeight = 1080;

    const unsigned char bluegreen[] = {0, 170, 255};

    cimg_library::CImg<unsigned char> bg(canvasWidth,canvasHeight,1,3, 255);

    bg.save("file.bmp");

    return 0;
}