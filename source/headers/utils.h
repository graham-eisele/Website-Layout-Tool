#include "CIMG.h"
#include "Box.h"
#include "Text.h"
#include "TextBox.h"
#include "CheckMark.h"
#include "Button.h"
#include "RadioOption.h"
#include "ImagePlaceholder.h"
#include "Captcha.h"
#include "Layout.h"

#include "../rapidjson/document.h"
#include "../rapidjson/filereadstream.h"

#include "opencv2/opencv.hpp"

class utils
{
public:

     static void drawLayout(Layout layout, std::string filename);

     static void drawBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Box box);
     static void drawText(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Text text);
     static void drawButton(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Button button);
     static void drawRoundedBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Box box);
     static void drawRadioOption(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, RadioOption box);
     static void drawTextBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, TextBox box);
     static void drawCheckBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, CheckMark checkBox);
     static void drawImagePlaceholder(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, ImagePlaceholder imagePlaceHolder);
     static void drawCaptcha(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Captcha captcha);


     static Box randomBox(int maxWidth, int maxHeight);
     static Text randomText();
     static Button randomButton(int maxWidth, int maxHeight);
     static TextBox randomTextBox(int maxWidth, int maxHeight);
     static CheckMark randomCheckBox(int maxWidth, int maxHeight);
     static RadioOption randomRadioOption(int maxWidth, int maxHeight);
     static ImagePlaceholder randomImagePlaceholder(int maxWidth, int maxHeight);
     static Captcha randomCaptcha(int maxWidth);

     static int randomInt(int min, int max);
     static int randomThickness(int min, int max);
     static Color randomColor();
     static std::string randomString();
     static bool randomBool();

     static int mutateInt(int original, int max);    
     static Color mutateColor(Color originalColor);
     static std::string mutateString(std::string originalString);
     static char randomCharacter();

     static rapidjson::Document loadJson(std::string jsonPath);

     //creates a layout object from a json file
     static Layout getLayout(std::string jsonPath);

     static Box parseBox(rapidjson::Value& object, int index);
     static Text parseText(rapidjson::Value& object, int index);
     static Button parseButton(rapidjson::Value& object, int index);
     static TextBox parseTextBox(rapidjson::Value& object, int index);
     static CheckMark parseCheckBox(rapidjson::Value& object, int index);
     static RadioOption parseRadioOption(rapidjson::Value& object, int index);
     static ImagePlaceholder parseImagePlaceholder(rapidjson::Value& object, int index);
     static Captcha parseCaptcha(rapidjson::Value& object, int index);

     static Color parseColor(rapidjson::Value& colorArray);

     static int getPixelDiff(std::string imageOne, std::string imageTwo);
     static int count_diff_pixels(cv::Mat in1, cv::Mat in2);

     static Layout mutateLayout(Layout layout);
     
private:
   
};
