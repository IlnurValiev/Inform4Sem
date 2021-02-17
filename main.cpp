#include "lib-1.h"
#include <iostream>
#include <stdio.h>

int main() {
    Vector2D A(3.14, 2.7);
    
    Vector2D B(1.2, 2.3);

    Vector2D C = A;

    std:: cout << "x = pi =  " << A.get_x() << '\n';
    std:: cout << "y = e = " << A.get_y() << "\n\n";

    std:: cout << "x = pi + 1.2 = " << (A+B).get_x() << '\n';
    std:: cout << "y = e + 2.3 = " << (A+B).get_y() << "\n\n";

    std:: cout << "x = pi - 1.2 = " << (A+B).get_x() << '\n';
    std:: cout << "y = e - 2.3 = " << (A+B).get_y() << "\n\n";

    std:: cout << "x = pi * 1.2 = " << (A+B).get_x() << '\n';
    std:: cout << "y = e * 2.3 = " << (A+B).get_y() << "\n\n";

    std:: cout << "x = pi / 1.2 = " << (A+B).get_x() << '\n';
    std:: cout << "y = e / 2.3 = " << (A+B).get_y() << "\n\n";

    A++;
    
    std:: cout << "pi + 1 = " << A.get_x() << '\n';
    std:: cout << "e + 1 = " << A.get_y() << "\n\n";

    A--;

    std:: cout << "4.14 - 1 = " << A.get_x() << '\n';
    std:: cout << "3.7 + 1 = " << A.get_y() << "\n\n";

    A += B;

    std:: cout << "x = pi + 1.2 = " << A.get_x() << '\n';
    std:: cout << "y = e + 2.3 = " << A.get_y() << "\n\n";

    A -= B;

    std:: cout << "x = 4.34 - 1.2 = " << A.get_x() << '\n';
    std:: cout << "y = 5 - 2.3 = " << A.get_y() << "\n\n";
    
    A *= B;

    std:: cout << "x = pi * 1.2 = " << A.get_x() << '\n';
    std:: cout << "y = 2.7 * 2.3 = " << A.get_y() << "\n\n";

    A /= B;

    std:: cout << "x = 3.768 / 1.2 = " << A.get_x() << '\n';
    std:: cout << "y = 6.21 / 2.3 = " << A.get_y() << "\n\n";

    std:: cout << "not pi = " << (!A).get_x() << '\n';
    std:: cout << "not e = " << (!A).get_y() << "\n\n";

    if(A == C)
        std:: cout << true << "\n\n";
    else std:: cout << false << "\n\n";
    
    if(A != B)
        std:: cout << true << "\n\n";
    else std:: cout << false << "\n\n";

    if(A >= B)
        std:: cout << true << "\n\n";
    else std:: cout << false << "\n\n";

    if(A <= B)
        std:: cout << true << "\n\n";
    else std:: cout << false << "\n\n";
}
