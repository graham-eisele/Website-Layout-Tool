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

    std::string first_command = "";
    std::string second_command = "";

    std::string input_filename = "";
    std::string output_filename  = "";

    for(int i = 0; i < argc; i++)
    {
        std::string current_argument = argv[i];

        if(current_argument.substr(0, 13) == "--input_file=")
        {
            input_filename = current_argument.substr(13);
        }
        else if(current_argument.substr(0, 14) == "--output_file=")
        {
             output_filename = current_argument.substr(14);
        }
    
  
        if(input_filename.length() > 0)
        {
            if(output_filename.length() > 0)
            {
                utils::drawLayout( utils::getLayout(input_filename), output_filename);
            }
            else
            {
                utils::drawLayout( utils::getLayout(input_filename), "output");
            }
        }
        
    }

    return 0;
}