#include "lib-1.h"

Vector2D:: Vector2D(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector2D:: Vector2D() {
    x = 3.14;
    y = 2.7;
}

/*Vector2D:: ~Vector2D() {
    cout << "Hello world" << endl;
}*/

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

Vector2D Vector2D:: operator +(Vector2D A) {
    return *new Vector2D(this->x + A.get_x(), this->y + A.get_y());
}

Vector2D Vector2D:: operator -(Vector2D A) {
    return *new Vector2D(this->x - A.get_x(), this->y - A.get_y());
}

Vector2D Vector2D:: operator *(Vector2D A) {
    return *new Vector2D(this->x * A.get_x(), this->y * A.get_y());
}

Vector2D Vector2D:: operator /(Vector2D A) {
    return *new Vector2D(this->x / A.get_x(), this->y / A.get_y());
}

void Vector2D:: operator ++(int) {
    x = x + 1.0;
    y = y + 1.0;
}

void Vector2D:: operator --(int) {
    x = x - 1.0;
    y = y - 1.0;
}

int Vector2D:: operator ==(Vector2D A) {
    if((this->x == A.get_x()) && (this->y == A.get_y())) 
        return 1;
    else return 0;
}

int Vector2D:: operator !=(Vector2D A) {
    if(*this == A)
        return 0;
    else return 1;
}

int Vector2D:: operator >(Vector2D A) {
    if((this->x > A.get_x()) && (this->y > A.get_y())) 
        return 1;
    else return 0;
}

int Vector2D:: operator <(Vector2D A) {
    if((this->x < A.get_x()) && (this->y < A.get_y())) 
        return 1;
    else return 0;
}

int Vector2D:: operator <=(Vector2D A) {
    if((this->x <= A.get_x()) && (this->y <= A.get_y())) 
        return 1; 
    else return 0;
}

int Vector2D:: operator >=(Vector2D A) {
    if((this->x >= A.get_x()) && (this->y >= A.get_y())) 
        return 1;
    else return 0;
}

void Vector2D:: operator +=(Vector2D A) {
    this->x += A.get_x();
    this->y += A.get_y();
}

void Vector2D:: operator -=(Vector2D A) {
    this->x -= A.get_x();
    this->y -= A.get_y();
}

void Vector2D:: operator *=(Vector2D A) {
    this->x *= A.get_x();
    this->y *= A.get_y();
}


void Vector2D:: operator /=(Vector2D A) {
    this->x /= A.get_x();
    this->y /= A.get_y();
}





