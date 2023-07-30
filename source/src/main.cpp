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

int main(int argc, const char* argv[])
{
    
    Layout layout;

    std::string first_comandline_argument = argv[1];
    std::string second_comandline_argument = argv[1];
    
    std::string first_command = first_comandline_argument.substr(0, 13);
    std::string second_command = first_comandline_argument.substr(0, 13);

    if(first_command == "--input_file=")
    {
        std::string input_filename = first_comandline_argument.substr(13);

        std::string output_filename = "output";

        if(second_command == "--output_file=")
        {
            output_filename = second_comandline_argument.substr(13);
        }
        
         utils::drawLayout( utils::getLayout(input_filename), output_filename);
    }

    return 0;
}