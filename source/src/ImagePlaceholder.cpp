#include "../headers/ImagePlaceholder.h"
#include <iostream>

ImagePlaceholder::ImagePlaceholder(std::string id, int w, int h)
{   
    this->id = id;
    
    this->width = w;
    this->height = h;

}

const int ImagePlaceholder::getWidth()
{
    return width;
}

const int ImagePlaceholder::getHeight()
{
    return height;
}

std::string ImagePlaceholder::getId()
{
    return id;
}

void ImagePlaceholder::setIndex(int index)
{
    this->index = index;
}
int ImagePlaceholder::getIndex()
{
    return index;
}