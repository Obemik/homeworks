#include <iostream>
#include <iomanip>

using namespace std;

class Complex {
    double real;
    double imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }
    double getReal() { return real; }
    double getImag() { return imag; }

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) {
        double newReal = (real * other.real) - (imag * other.imag);
        double newImag = (real * other.imag) + (imag * other.real);
        return Complex(newReal, newImag);
    }

    Complex operator/(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        double newReal = (real * other.real + imag * other.imag) / denominator;
        double newImag = (imag * other.real - real * other.imag) / denominator;
        return Complex(newReal, newImag);
    }

    void print() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    cout << "c1 = "; c1.print();
    cout << "c2 = "; c2.print();

    cout << "Sum = "; sum.print();
    cout << "Difference = "; diff.print();
    cout << "Product = "; prod.print();
    cout << "Quotient = "; quot.print();

    return 0;
}