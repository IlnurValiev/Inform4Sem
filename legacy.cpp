#include <iostream>

class Human {
    //private не наследуется, а protected позволяет наследовать
    protected:
        std:: string name;
        int age;
    public:
        Human();
        Human(std:: string, int);
        std:: string get_name();
        int get_age();
        void set_age(int);
        void set_name(std:: string);
};
// protected наследует все в виде prot., private наследует приватную часть и публичную в приватные

class Student : public Human {
    int score;
    public:
        Student();
        Student(std:: string, int, int);
        int get_score();
        void set_score(int);
        virtual std:: string get_name();
};

class Teacher : public Human {
    int salary;
    public:
        Teacher();
        Teacher(std:: string, int, int);
        int get_salary();
        void set_salary(int);
        std:: string get_name();
};

Human:: Human() {
    name = "";
    age = 0;
}

Human:: Human(std:: string name, int age) {
    this->name = name;
    this->age = age;
}

int Human:: get_age() {
    return age;
}

std:: string Human:: get_name() {
    return name;
}
void Human:: set_age(int age) {
    this->age = age;
}

void Human:: set_name(std:: string name) {
    this->name = name;
}

Student:: Student() : Human() {
    score = 0;
}

Student:: Student(std:: string name, int age, int score) : Human(name, age) {
    this->score = score;
}

int Student:: get_score() {
    return score;
}

void Student:: set_score(int score) {
    this->score = score;
}

Teacher:: Teacher() : Human() {
    salary = 0;
}

Teacher:: Teacher(std:: string name, int age, int score) : Human(name, age) {
    this->salary = salary;
}

int Teacher:: get_salary() {
    return salary;
}

void Teacher:: set_salary(int salary) {
    this->salary = salary;
}

std:: string Teacher:: get_name() {
    return "Prof. " + name;
}

std:: string Student:: get_name() {
    return "Student "+ name;
}

int main() {
    Human *A = new Student("Vasya", 21, 2);
    Student *B = new Student("Petya", 20, 5);
    std:: cout << A->get_name() << '\n' << B->get_name() << '\n';
}
