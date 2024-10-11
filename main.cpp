#include <iostream>
using namespace std;

class Transport
{
public:
    virtual double calculateTime(double distance) = 0;
    virtual double calculateCost(double weight) = 0;
    virtual ~Transport() {}
};

class Car : public Transport
{
private:
    double speed;
    double costPerKg;
public:
    Car(double s, double cost) : speed(s), costPerKg(cost) {}

    double calculateTime(double distance) override
    {
        return distance / speed;
    }

    double calculateCost(double weight) override
    {
        return weight * costPerKg;
    }
};

class Bicycle : public Transport
{
private:
    double speed;
    double costPerKg;
public:
    Bicycle(double s, double cost) : speed(s), costPerKg(cost) {}

    double calculateTime(double distance) override
    {
        return distance / speed;
    }

    double calculateCost(double weight) override
    {
        return weight * costPerKg;
    }
};

class Cart : public Transport
{
private:
    double speed;
    double costPerKg;
public:
    Cart(double s, double cost) : speed(s), costPerKg(cost) {}

    double calculateTime(double distance) override
    {
        return distance / speed;
    }

    double calculateCost(double weight) override
    {
        return weight * costPerKg;
    }
};

int main()
{
    double distance = 100;
    double weight = 200;

    Car car(80, 5);
    Bicycle bicycle(20, 2);
    Cart cart(10, 1);

    cout << "Car:" << endl;
    cout << "Time: " << car.calculateTime(distance) << " hours" << endl;
    cout << "Cost: " << car.calculateCost(weight) << " UAH" << endl << endl;

    cout << "Bicycle:" << endl;
    cout << "Time: " << bicycle.calculateTime(distance) << " hours" << endl;
    cout << "Cost: " << bicycle.calculateCost(weight) << " UAH" << endl << endl;

    cout << "Cart:" << endl;
    cout << "Time: " << cart.calculateTime(distance) << " hours" << endl;
    cout << "Cost: " << cart.calculateCost(weight) << " UAH" << endl;

    return 0;
}