#include <iostream>
using namespace std;

template <typename T>
class Circledw
{
protected:
    T diameter;
public:
    Circledw() {
        cout << "Circle constructor" << endl;
        diameter = T(2);
    }

    Circledw(T value) {
        cout << "Circle constructor with value" << endl;
        this->diameter = value;
    }

    virtual void get_value() {
        cout << "Diameter from Circle: " << diameter << endl;
    }

    virtual ~Circledw() {
        cout << "Circle destructor" << endl;
    }
};

template <typename T>
class Squaredw
{
protected:
    T size;
public:
    Squaredw() {
        size = T(1); 
        cout << "Square constructor" << endl;
    }

    Squaredw(T value) {
        this->size = value;
        cout << "Square constructor with value" << endl;
    }

    virtual void get_value() {
        cout << "Size from Square: " << size << endl;
    }

    virtual ~Squaredw() {
        cout << "Square destructor" << endl;
    }
};

template <typename T>
class CircleInSquaredw : public Circledw<T>, public Squaredw<T>
{
public:
    CircleInSquaredw() {
        cout << "CircleInSquare constructor" << endl;
    }

    CircleInSquaredw(T value) : Circledw<T>(value), Squaredw<T>(value) {
        cout << "CircleInSquare constructor with value" << endl;
    }

    void get_value() override {
        cout << "Diameter from CircleInSquare: " << Circledw<T>::diameter << endl;
        cout << "Size from CircleInSquare: " << Squaredw<T>::size << endl;
    }

    virtual ~CircleInSquaredw() {
        cout << "CircleInSquare destructor" << endl;
    }
};

int main() {
    Circledw<int> circle(5);  
    Squaredw<int> square(10); 
    CircleInSquaredw<int> circleInSquare(15); 

    cout << endl;
    circle.get_value();
    square.get_value();
    circleInSquare.get_value();

    return 0;
}
