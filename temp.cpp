#include <iostream>

template <typename T> 

T sum(T a, T b) {
    return a+b;
}

int sum(int a, int b) {
    return a+b;
}

double sub(double a, double b) {
    return a+b;
}

int main() {
    int x = 1;
    int y = 2;
    int z;
    z = sum<int>(x,y);
    std:: cout << z << '\n';

    double pi = 3.14;
    double e = 2.7;
    std:: cout <<  sum<double>(pi, e) << '\n';
}
