 #ifndef COLOR_H
 #define COLOR_H
class Color
{
    public:
        Color();
        Color(int r, int g, int b);
        int getR();
        int getG();
        int getB();
    
    private:

        int r;
        int g;
        int b;
};

#endif