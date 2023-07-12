#include "CIMG.h"

template <typename E>

class utils
{
public:

    static void drawElement(cimg_library::CImg<unsigned char> &canvas, int startX, int startY, E e);

private:

    void drawBox(cimg_library::CImg<unsigned char> &canvas);
};
