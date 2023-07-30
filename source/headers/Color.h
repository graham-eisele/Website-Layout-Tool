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

        void setR(int r);
        void setG(int g);
        void setB(int b);
        void setA(int a);
    
    private:

        int r;
        int g;
        int b;
        int a;
};

#endif