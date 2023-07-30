#ifndef CAPTCHA_H
#define CAPTCHA_H
#include <string>

class Captcha
{
public:
    //default box constructor
    Captcha(std::string id, int w);

    const int getWidth();

    std::string getId();

    void setIndex(int index);
    int getIndex();

    void mutate();

private:
    
    int width;

    std::string id;

    int index;
    
};
#endif