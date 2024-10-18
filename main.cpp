#include <iostream>
using namespace std;

template<typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;
public:
    Base() {
        cout << "Base constructor" << endl;
        value1 = T1();
        value2 = T2();
    }

    Base(T1 value1, T2 value2) {
        cout << "Base constructor with values" << endl;
        this->value1 = value1;
        this->value2 = value2;
    }

    void Sum() {
        cout << "Sum from Base: " << value1 + value2 << endl;
    }

    void average() {
        cout << "Average from Base: " << (value1 + value2) / 2 << endl;
    }

    virtual void get_value() {
        cout << "Value from Base: " << value1 << " " << value2 << endl;
    }

    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

template<typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1, T2> {
protected:
    T3 value3;
    T4 value4;
public:
    Child() : Base<T1, T2>() {
        cout << "Child constructor" << endl;
        value3 = T3();
        value4 = T4();
    }

    Child(T1 value1, T2 value2, T3 value3, T4 value4) : Base<T1, T2>(value1, value2) {
        cout << "Child constructor with values" << endl;
        this->value3 = value3;
        this->value4 = value4;
    }

    void Sum() {
        cout << "Sum from Child: " << this->value1 + this->value2 + value3 + value4 << endl;
    }

    void average() {
        cout << "Average from Child: " << (this->value1 + this->value2 + value3 + value4) / 4 << endl;
    }

    virtual void get_value() {
        cout << "Value from Child: " << this->value1 << " " << this->value2 << " " << value3 << " " << value4 << endl;
    }

    virtual ~Child() {
        cout << "Child destructor" << endl;
    }
};

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;
public:
    Child2() : Child<T1, T2, T3, T4>() {
        cout << "Child2 constructor" << endl;
        value5 = T5();
        value6 = T6();
    }

    Child2(T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6)
        : Child<T1, T2, T3, T4>(value1, value2, value3, value4) {
        cout << "Child2 constructor with values" << endl;
        this->value5 = value5;
        this->value6 = value6;
    }

    void Sum() {
        cout << "Sum from Child2: " << this->value1 + this->value2 + this->value3 + this->value4 + value5 + value6 << endl;
    }

    void average() {
        cout << "Average from Child2: " << (this->value1 + this->value2 + this->value3 + this->value4 + value5 + value6) / 6 << endl;
    }

    virtual void get_value() {
        cout << "Value from Child2: " << this->value1 << " " << this->value2 << " " << this->value3 << " " << this->value4 << " " << value5 << " " << value6 << endl;
    }

    virtual ~Child2() {
        cout << "Child2 destructor" << endl;
    }
};

int main() {
    Base<int, double> b(1, 2.0);
    Child<int, double, int, int> c(2, 0.5, 1, 5);
    Child2<int, double, int, int, int, int> c2(3, 0.3, 2, 4, 6, 8);

    cout << endl;
    b.get_value();
    b.Sum();
    b.average();

    cout << endl;
    c.get_value();
    c.Sum();
    c.average();

    cout << endl;
    c2.get_value();
    c2.Sum();
    c2.average();

    cout << endl;

    return 0;
}