#include <deque>
#include <iostream>
#include <stdlib.h>

class TimeHm {
    protected:
        int hours;
        unsigned int mins;
    public:
        TimeHm();
        TimeHm(int, int);
        virtual void reg();
        int get_m();
        int get_h();
        void set_m(int);
        void set_h(int);
        friend TimeHm operator+(const TimeHm &, const TimeHm &);
        friend TimeHm operator-(const TimeHm &, const TimeHm &);
};

class TimeHms : public TimeHm {
    unsigned int sec;
    public:
        TimeHms();
        TimeHms(int, int, int);
        void reg();
        int get_s();
        void set_s(int);
        friend TimeHms operator+(const TimeHms &, const TimeHms &);
        friend TimeHms operator-(const TimeHms &, const TimeHms &);
};

TimeHm:: TimeHm() {
    hours = 0;
    mins = 0;
}

TimeHm:: TimeHm(int h, int m) {
    if((m<0) && (h<0)) {
        h = -h;
        m = -m;
        hours = h;
        mins = m;
    }
    else if(m<0) {
        m = -m;
        hours = -h;
    }

}

void TimeHm:: reg() {
    hours += mins/60;
    mins %= 60;
}

int TimeHm:: get_h() {
    return hours;
}

int TimeHm:: get_m() {
    return mins;
}

void TimeHm:: set_h(int h) {
    hours = h;
    this->reg();
}

void TimeHm:: set_m(int m) {
  if(m<0) throw 1;
    
    try {
        mins = m;
        this->reg();
    }
    catch(int) {
        m = -m;
        hours -= m/60;
        m %= 60;
        m -= 60;
        mins = m;
    }
}

TimeHm operator+(const TimeHm &A, const TimeHm &B) {
    TimeHm C(A.hours+B.hours, A.mins+B.mins);
    return C;
}

TimeHm operator-(const TimeHm &A, const TimeHm &B) {
    TimeHm C(A.hours-B.hours, A.mins-B.mins);
    return C;
}

void TimeHms:: reg() {
    mins += sec/60;
    sec %= 60;
    hours += mins/60;
    mins %= 60;
}

TimeHms:: TimeHms(int h, int m, int s) : TimeHm(h,m) {
    sec = s;
    this->reg();
}

TimeHms:: TimeHms() : TimeHm() {
    sec = 0;
}

int TimeHms:: get_s() {
    return sec;
}

void TimeHms:: set_s(int s) {
    sec = s;
}

TimeHms operator+(const TimeHms &A, const TimeHms &B) {
    TimeHms C(A.hours+B.hours, A.mins+B.mins, A.sec+B.sec);
    return C;
}

TimeHms operator-(const TimeHms &A, const TimeHms &B) {
    TimeHms C(A.hours-B.hours, A.mins-B.mins, A.sec-B.sec);
    return C;
}

template <typename T>
class Lesson{
    T time;
    std:: deque<std:: string> students;
    public:
        Lesson();
        Lesson(T,std:: deque<std:: string>);
        T get_time();
        std:: deque<std:: string> get_student(int i);
        void set_time(T);
        void set_student(std:: deque<std:: string>);
        void add_stud(std:: deque<std:: string>);
        void del_stud( std:: deque<std:: string>);
        
        template <typename T1>
        friend Lesson<T1>operator+(const Lesson &, const T1 &);

        template <typename T1>
        friend Lesson<T1>operator-(const Lesson &, const T1 &);
};

template <typename T>
Lesson<T>:: Lesson() {
    if (T != "TimeHms" && (T != "double") && (T != "int"))
        throw 1;
    try {
        if(T == "TimeHm") {
            time.h = 0;
            time.m = 0;
        }
        else if(T == "TimeHms" || (T == "double") || (T == "int")) {
            time.h = 0;
            time.m = 0;
            time.s = 0;
        }
    }
    catch(int) {
        std:: cout << "Invalid time type";
    }
}

template <typename T>
Lesson<T>:: Lesson(T time, deque<std:: string> students) {
    if (T != TimeHms && (T != double) && (T != int) && (T != TimeHm))
        throw 1;
    if(sizeof(students) > 20)
        throw 1.1;
    try {
        if(T == TimeHm) {
            this->time.hours = time.hours;
            this->time.mins = time.mins;
        }
        else if(T == TimeHms) {
            this->time.hours = time.hours;
            this->time.mins = time.mins;
            this->time.sec = time.sec;
        }
        else if (T==int) {
            this->time.hours = time/60;
            this->time.mins = time%60;
        }
        else if(T==double) {
            this->time.sec = (time - (int)time)*60;
            this->time.hours = ((int)time)/60;
            this->time.mins = ((int)time)%60;
        }
        this->time.reg();
        this->students = students;
    }
    catch(int) {
        std:: cout << "Invalid time type";
        exit(-1);
    }
    catch(double) {
        std:: cout << "student name's lenght mustn't be more then 20";
        exit(-1);
    }
}

template <typename T>
T Lessson<T>:: get_time() {
    return time;
}

template <typename T>
std:: deque<std:: string> Lesson<T> get_student(int i) {
    return students[i];
}

template <typename T>
void set_time(T time) {
    if (T != TimeHms && (T != double) && (T != int) && (T != TimeHm))
        throw 1;
    try {
        this->time = time;
        this->time.reg();
    }
    catch(int) {
        std:: cout << "Invalid time type";
        exit(-1);
    }
}

template <typename T>
void Lesson<T> set_student(std:: deque<std:: string> stud) {
    students = stud;
}

template <typename T>
void Lesson<T> add_stud(std:: string stud) {
    if(sizeof(stud)>20)
        throw 1;
    try 
        students.push_back(stud);
    catch(int) {
        std:: cout << "student name's lenght mustn't be more then 20";
        exit(-1);
    } 
}









