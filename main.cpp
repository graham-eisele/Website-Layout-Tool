#include <iostream>
#include "element.h"
#include "utils.h"
#include "Box.h"
#include "CIMG.h"

int main(int argc, const char** argv)
{
    

    unsigned int w = 1920;
    unsigned int h = 1080;

    const unsigned char bluegreen[] = {0, 170, 255};

    cimg_library::CImg<unsigned char> bg(w,h,1,3, 255);

    Color blue(65, 105, 225);

    Box box(300, 500, blue, 100, Color(200, 200, 200));

    utils<Box>::drawElement(bg, 0, 0, box);

    bg.save("file.bmp");

    return 0;
}