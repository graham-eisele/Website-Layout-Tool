#include "CIMG.h"
#include "Box.h"
#include "Text.h"

class utils
{
public:

     static void drawBox(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Box box);
     static void drawText(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, Text text);
 
private:

   
};