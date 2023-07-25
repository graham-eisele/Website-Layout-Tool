#include <iostream>
#include "../headers/utils.h"

#include "../headers/Box.h"
#include "../headers/Text.h"
#include "../headers/TextBox.h"
#include "../headers/Button.h"
#include "../headers/CheckMark.h"
#include "../headers/RadioOption.h"
#include "../headers/Captcha.h"


#include "../rapidjson/document.h"
#include "../rapidjson/filereadstream.h"

#include "../headers/CImg.h"
#include "opencv2/opencv.hpp"

int main(int argc, const char** argv)
{
    
    Layout test = utils::getLayout("example.json");
    utils::drawLayout(test, "test");

    return 0;
}