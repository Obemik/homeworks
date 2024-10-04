#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Fraction
{
    int _numerator;
    int _denominator;

public:
    Fraction() {
        _numerator = 0;
        _denominator = 1;
    }

    Fraction(int full, int numerator, int denominator) : Fraction() {
        _numerator = numerator + full * denominator;
        _denominator = denominator;
    }

    Fraction(int numerator, int denominator) : Fraction() {
        _numerator = numerator;
        _denominator = denominator;
    }

    void setNumerator(int numerator) { _numerator = numerator; }
    void setDenominator(int denominator) { _denominator = denominator; }

    int getNumerator() { return _numerator; }
    int getDenominator() { return _denominator; }

    void reduce() {
        int gcd = 1;
        int smaller = _numerator < _denominator ? _numerator : _denominator;
        for (int i = 1; i <= smaller; i++) {
            if (_numerator % i == 0 && _denominator % i == 0) {
                gcd = i;
            }
        }
        _numerator /= gcd;
        _denominator /= gcd;
    }

    void print() {
        if (_numerator != 0) {
            cout << _numerator << "/" << _denominator;
        }
        cout << endl;
    }

    void printDecimal() {
        cout << double(_numerator) / double(_denominator) << endl;
    }

    void printWrongFraction() {
        int full = _numerator / _denominator;
        int realNumerator = _numerator % _denominator;
        cout << full << " " << realNumerator << "/" << _denominator << endl;
    }

    Fraction operator+(const Fraction& other) {
        int commonDenominator = GetSmallestCommonDenominator(_denominator, other._denominator);
        int numerator1 = _numerator * (commonDenominator / _denominator);
        int numerator2 = other._numerator * (commonDenominator / other._denominator);
        Fraction result(numerator1 + numerator2, commonDenominator);
        result.reduce();
        return result;
    }

    Fraction operator-(const Fraction& other) {
        int commonDenominator = GetSmallestCommonDenominator(_denominator, other._denominator);
        int numerator1 = _numerator * (commonDenominator / _denominator);
        int numerator2 = other._numerator * (commonDenominator / other._denominator);
        Fraction result(numerator1 - numerator2, commonDenominator);
        result.reduce();
        return result;
    }

    Fraction operator*(const Fraction& other) {
        Fraction result(_numerator * other._numerator, _denominator * other._denominator);
        result.reduce();
        return result;
    }

    Fraction operator/(const Fraction& other) {
        Fraction result(_numerator * other._denominator, _denominator * other._numerator);
        result.reduce();
        return result;
    }

    int GetSmallestCommonDenominator(int a, int b) {
        int result = a;
        while (result % b != 0) {
            result += a;
        }
        return result;
    }
};

int main() {
    Fraction f1(1, 2, 5);
    Fraction f2(1, 3, 5);

    Fraction f3 = f1 + f2;
    f3.print(); 

    Fraction f4 = f1 - f2;
    f4.print();

    Fraction f5 = f1 * f2;
    f5.print(); 

    Fraction f6 = f1 / f2;
    f6.print(); 

    return 0;
}