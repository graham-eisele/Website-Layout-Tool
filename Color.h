 #ifndef COLOR_H
 #define COLOR_H
class Color
{
    public:
        Color();
        Color(int r, int g, int b, int a);
        int getR();
        int getG();
        int getB();
        int getA();
    
    private:

        int r;
        int g;
        int b;
        int a;
};

#endif