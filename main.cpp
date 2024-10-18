#include <iostream>
using namespace std;

class Wheels {
private:
    int wheelCount;
public:
    Wheels(int wheelCount) : wheelCount(wheelCount) {}

    void showWheels() {
        cout << "Count of wheels: " << wheelCount << endl;
    }
};

class Engine {
private:
    int horsepower;
public:
    Engine(int horsepower) : horsepower(horsepower) {}

    void showEngine() {
        cout << "Engine power: " << horsepower << " HP" << endl;
    }
};

class Doors {
private:
    int doorCount;
public:
    Doors(int doorCount) : doorCount(doorCount) {}

    void showDoors() {
        cout << "Count of doors: " << doorCount << endl;
    }

};

class Car : public Wheels, public Engine, public Doors {
public:
    Car(int wheelCount, int horsepower, int doorCount)
        : Wheels(wheelCount), Engine(horsepower), Doors(doorCount) {}

    void showCar() {
        showWheels();
        showEngine();
        showDoors();
    }
};

int main() {
    Car myCar(4, 150, 4);
    myCar.showCar();

    return 0;
}
