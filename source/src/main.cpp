#include <iostream>
#include "../headers/utils.h"

#include "../headers/Box.h"
#include "../headers/Text.h"
#include "../headers/TextBox.h"
#include "../headers/Button.h"
#include "../headers/CheckMark.h"
#include "../headers/RadioOption.h"

#include "../headers/CImg.h"
#include "opencv2/opencv.hpp"

int main(int argc, const char** argv)
{
    

    unsigned int canvasWidth = 1920;
    unsigned int canvasHeight = 1080;

    const unsigned char bluegreen[] = {0, 170, 255};

    cimg_library::CImg<unsigned char> bg(canvasWidth,canvasHeight,1,3, 255);

    bg.save("file.bmp");

    return 0;
}