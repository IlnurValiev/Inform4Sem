#include <iostream>

class Frac {
    int num, den;

    public:
        Frac();
        Frac(int, int);
        Frac(double);

        void reduct();

        void set_num(int);
        void set_den(int);

        int get_num();
        int get_den();

        int intgr();//целая часть
        double fract();//дробная часть

        friend Frac operator+(const Frac &, const Frac &);
        friend Frac operator+(const Frac &, const double &);
        friend Frac operator+(const double &,const Frac &);
        friend Frac operator-(const Frac &, const Frac &);
        friend Frac operator-(const Frac &A, const double &a);
        friend Frac operator-(const double &a, const Frac &A);
        friend Frac operator*(const Frac &, const Frac &);
        friend Frac operator*(const double &, const Frac &);
        friend Frac operator*(const Frac &, const double &);
        friend Frac operator/(const Frac &, const Frac &);
        friend Frac operator/(const Frac &A, const double &a);
        friend Frac operator/(const double &a, const Frac &A);
        friend Frac operator++(Frac &);
        friend Frac operator++(Frac &, int);
        friend Frac operator--(Frac &);
        friend Frac operator--(Frac &, int);
        friend void operator+=(Frac &, const Frac &);
        friend void operator-=(Frac &, const Frac &);
        friend void operator*=(Frac &, const Frac &);
        friend void operator/=(Frac &, const Frac &);
        friend bool operator==(Frac &, Frac &);
        friend bool operator>(const Frac &, const Frac &);
        friend bool operator<(const Frac &, const Frac &);
        friend bool operator>=(const Frac &, const Frac &);
        friend bool operator<=(const Frac &, const Frac &);
        friend bool operator!=(const Frac &, const Frac &);
        friend std:: ostream &operator<<(std::ostream &, Frac &);
        friend std:: istream &operator>>(std::istream &, Frac &);
};