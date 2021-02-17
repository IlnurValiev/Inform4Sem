#include <iostream>


class Vector2D {
    double x, y;
    public: 
        Vector2D();
        Vector2D(double _x, double _y);
        //~Vector2D();
        void set_x(double _x);
        void set_y(double _y);
        double get_x();
        double get_y();
        Vector2D operator +(Vector2D);
        Vector2D operator -(Vector2D);
        Vector2D operator *(Vector2D);
        Vector2D operator /(Vector2D);
        void operator ++(int);
        void operator --(int);
        int operator ==(Vector2D);
        int operator !=(Vector2D);
        int operator >(Vector2D);
        int operator <(Vector2D);
        int operator <=(Vector2D);
        int operator >=(Vector2D);
        Vector2D operator !(void);
        void operator +=(Vector2D);
        void operator -=(Vector2D);
        void operator *=(Vector2D);
        void operator /=(Vector2D);
};

Vector2D sum(Vector2D A, Vector2D B); 
double sum(double a, double b); //перегрузка
