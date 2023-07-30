#ifndef IMAGEHOLDER_H
#define IMAGEHOLDER_H
#include <string>

class ImagePlaceholder
{
public:
    //default box constructor
    ImagePlaceholder(std::string id, int w, int h);

    const int getWidth();
    const int getHeight();

    std::string getId();

    void setIndex(int index);
    int getIndex();

    void mutate();

private:
    
    int width;
    int height;

    std::string id;

    int index;
    
};
#endif