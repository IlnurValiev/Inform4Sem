#include <math.h>
#include <iostream>

class Fig {
    public:
        virtual double per() {
            return 0;
        }
        virtual double area() {
            return 0;
        }
};

class Trian : public Fig {
    double a,b,c;
    public:
        double per() {
            return a+b+c;
        }
        double area() {
            double p = this->per()/2;
            return sqrt((p-a)*(p-b)*(p-c)*p);
        }           
        Trian();
        Trian(double, double, double);
};

class Round : public Fig {
    double R;
    public:
        double per() {
            return 2*3.14*R;
        }
        double area() {          
            return 3.14*pow(R,2);
        }
        Round();
        Round(double);
};

class Quad : public Fig {
    protected:
        double a,b,c,d;
    public:
        virtual double per() {
            return a+b+c+d;
        }
        virtual double area() {
            double p = this->per()/2;
            return sqrt((p-d)*(p-a)*(p-b)*(p-c));
        }
        Quad();
        Quad(double, double, double, double);
};

class Rect : public Quad {
    public:
        Rect();
        Rect(double, double);
        double per() {
            return 2*(a+b);
        }
        double area() {
            return a*b;
        }
};

class Square : public Rect {
    public:
        double per() {
            return 4*a;
            }
        double area() {
            return pow(a,2);
        }
        Square();
        Square(double);   
};

Trian:: Trian() {
    a = 1;
    b = 1;
    c = 1;
}

Trian:: Trian(double a, double b, double c) {

    if((a >= b+c) || (b >= a+c) || (c >= a+b))
        std:: cout << "such triange can't exist\n";
    else {
        this->a = a;
        this->b = b;
        this->c = c;
        }
}

Round:: Round() {
    R = 1;
}

Round:: Round(double R) {
    this->R = R;
}

Quad:: Quad() {
    a = 1;
    b = 1;
    c = 1;
    d = 1;
}

Quad:: Quad(double a,double b,double c,double d) {
    if((a >= b+c+d) || (b >= a+c+d) || (c >= a+b+d) || (d >= a+b+c))
        std:: cout << "such quadrangle can't exist\n";
    else {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
} 

Rect:: Rect() {
    a = 1;
    b = 1;
    c = 1;
    d = 1;
}

Rect:: Rect(double a, double b) {
    this->a = a;
    this->b = b;
    c = a;
    d = b;
}

Square:: Square() {
    a = 1;
    b = 1;
    c = 1;
    d = 1;
}

Square:: Square(double a){
    this->a = a;
    this->b = b;
    this->c = a;
    this->d = a;
}

int main() {
    Fig *A = new Trian(2,2,3);
    std::cout << A->per() << '\n';
    std::cout << A->area() << '\n';

    Fig *B = new Round(2);
    std::cout << B->per() << '\n';
    std::cout << B->area() << '\n';

    Fig *C = new Quad(1,2,3,4);
    std::cout << C->per() << '\n';
    std::cout << C->area() << '\n';

    Fig *D = new Rect(1,2);
    std::cout << D->per() << '\n';
    std::cout << D->area() << '\n';

    Fig *E = new Square(2);
    std::cout << E->per() << '\n';
    std::cout << E->area() << '\n'; 
  
}