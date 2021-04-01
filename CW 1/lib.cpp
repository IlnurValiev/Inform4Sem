#include "lib.h"
#define min(a,b) a < b? a: b
#define abs(a) a < 0? -a: a

Frac:: Frac() {
    num = 1;
    den = 1;
}

Frac:: Frac(int a, int b) {
    
    if((b < 0) && (a > 0)) {
        b = abs(den);
        a = -a;
    }

    if((b < 0) && (a < 0)) {
        a = abs(a);
        a = abs(b);
    }

    if(b==0)
        std:: cout << "Denominator couldn't be equal 0\n";
    else {
        num = a;
        den = b;
    }
}

Frac:: Frac(double a) {
    num = a*100000;
    den = 100000;
    this->reduct();
}

 void Frac:: reduct() {
    for(int i = 2; i <= min(abs(num), abs(den)); i++) {
        if((abs(den)%i==0) && (abs(num)%i==0)) {
            num /= i;
            den /= i;
        }
    }
}

void Frac:: set_num(int a) {
    num = a;
}

void Frac:: set_den(int b) {
    den = b;
}

int Frac::  get_num() {
    return num;
}

int Frac:: get_den() {
    return den;
}

 int Frac:: intgr() {
    return (int)num/den;
}

double Frac:: fract() {
    int Int;
    double frac;
    Int = num/den;
    frac = num/den;
    return frac - Int;
}

Frac operator+(const Frac &A, const Frac &B) {
    Frac C(A.num*B.den + (A.den*B.num), A.den*B.den);
    
    C.reduct();

    return C;
}

Frac operator+(const Frac &A, const double &a) {
    Frac C(A.num + A.den*a, A.den);
    C.reduct();
    return C;
}

Frac operator+(const double &a,const Frac &A) {
    Frac C(A.num + A.den*a, A.den);
    C.reduct();
    return C;
}

Frac operator-(const Frac &A, const Frac &B) {
    Frac C(A.num*B.den - (A.den*B.num), A.den*B.den);
    
    C.reduct();

    return C;
}

Frac operator-(const double &a,const Frac &A) {
    Frac C(A.num - A.den*a, A.den);
    C.reduct();
    return C;
}

Frac operator-(const Frac &A, const double &a) {
    Frac C(A.num - A.den*a, A.den);
    C.reduct();
    return C;
}


Frac operator*(const Frac &A, const Frac &B) {   
    Frac C(A.num*B.num, A.den*B.den);
    C.reduct();
    return C;
}

Frac operator*(const double &a, const Frac &A) {
    Frac C(a*A.num, A.den);
    C.reduct();
    return C;
}

Frac operator*(const Frac &A, const double &a) {
    Frac C(a*A.num, A.den);
    C.reduct();
    return C;
}

Frac operator/(const Frac &A, const Frac &B) {
    Frac C(A.num*B.den, A.den*B.num);
    C.reduct();
    return C;
}

Frac operator/(const Frac &A, const double &a) {
    Frac C(A.num/a, A.den);
    C.reduct();
    return C;
}

Frac operator/(const double &a, const Frac &A) {
    Frac C(a*A.den, A.num);
    C.reduct();
    return C;
}

Frac operator++(Frac &A) {
    A.num = A.num + A.den;
    A.den = A.den;
    A.reduct();
    return A;
}

Frac operator++(Frac &A, int) {
    Frac B = A;
    A.num = A.num + A.den;
    A.den = A.den;
    A.reduct();
    return B;
}

Frac operator--(Frac &A) {
    A.num = A.num - A.den;
    A.den = A.den;
    A.reduct();
    return A;
}

Frac operator--(Frac &A, int) {
    Frac B = A;
    A.num = A.num - A.den;
    A.den = A.den;
    A.reduct();
    return B;
}

void operator+=(Frac &A, const Frac &B) {
    A = A + B;
    A.reduct();
}   

void operator-=(Frac &A, const Frac &B) {
    A = A - B;
    A.reduct();
}   

void operator*=(Frac &A, const Frac &B) {
    A = A * B;
    A.reduct();
}  

void operator/=(Frac &A, const Frac &B) {
    A = A / B;
    A.reduct();
} 

bool operator==(Frac A, Frac B) {
    A.reduct();
    B.reduct();
    if((A.get_num() == B.get_num()) && (A.get_den() == B.get_den()) )
        return true;
    else return false;

}

bool operator>(const Frac &A, const Frac &B) {
    if((A-B).get_num() > 0)
        return true;
    else 
        return false;
}

bool operator<(const Frac &A, const Frac &B) {
    if((A-B).get_num() > 0)
        return true;
    else 
        return false;
}

bool operator!=(const Frac &A, const Frac &B) {
    if(A == B)
        return false;
    else 
        return true;
}

std:: ostream &operator<<(std::ostream &out, Frac &A) {
    out << A.get_num() << '\n' << "—" << '\n' << A.get_den();
    return out;
}

std:: istream &operator>>(std::istream &in, Frac &A) {

    in >> A.num >> A.den;
    return in;
}

int main() {

}






