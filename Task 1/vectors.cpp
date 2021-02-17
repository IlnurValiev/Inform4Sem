#include <iostream>
using namespace std;

//инкапсуляция - у внешних функций нет доступа к локальным полям класс
//конструктор - при вызове сразу задаются начальные значения
//деструктор - метод вызывается при удалении
//при инициализации класса через дин. память нужен конструктор

class Vector2D {
    double x, y;
    public: 
        Vector2D();
        Vector2D(double _x, double _y);
        ~Vector2D();
        void set_x(double _x);
        void set_y(double _y);
        double get_x();
        double get_y();
};

Vector2D sum(Vector2D A, Vector2D B); 
double sum(double a, double b); //перегрузка

Vector2D:: Vector2D(double _x, double _y) {
    x = _x;
    y = _y;
}

Vector2D:: Vector2D() {
    x = 3.14;
    y = 2.7;
}

Vector2D:: ~Vector2D() {
    cout << "Hello world" << endl;
}

void Vector2D:: set_x(double _x) {
    x = _x ;
}

void Vector2D:: set_y(double _y) {
    y = _y ;
}

double Vector2D:: get_x() {
    return x;
}

double Vector2D:: get_y() {
    return y;
}

Vector2D sum(Vector2D A, Vector2D B) {
    return *new Vector2D(A.get_x() + B.get_x(), A.get_y() + B.get_y());
}

double sum(double a, double b) {
    return a+b;
}

int main() {
    int a, b;

    Vector2D *A;
    A = new Vector2D(3.14, 2.7);
    
    Vector2D *B;
    B = new Vector2D(1, 2);

    Vector2D *C;
    C = new Vector2D();

    cout << "x = pi = " << C->get_x() << endl;
    cout << "y = ei = " << C->get_y() << endl;
    cout << "x = pi + 1 = " << sum(*A, *B).get_x() << endl;
    cout << "y = e + 2 = " << sum(*A, *B).get_y() << endl;

}
