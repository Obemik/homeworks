#include <iostream>
#include <string>

using namespace std;

class Human {
private:
    string fullName;

public:
    Human() : fullName("Unnamed") {}

    Human(const string& name) {
        fullName = name;
    }

    Human(const Human& other) {
        fullName = other.fullName;
    }

    ~Human() {}

    void printName() const {
        cout << "Name: " << fullName << endl;
    }
};

class Apartment {
private:
    Human* residents;
    size_t size;
    size_t capacity;

    void copyResidents(const Human* src, size_t count) {
        for (size_t i = 0; i < count; i++) {
            residents[i] = src[i];
        }
    }

public:
    Apartment() : size(0), capacity(5) {
        residents = new Human[capacity];
    }

    Apartment(const Apartment& other) : size(other.size), capacity(other.capacity) {
        residents = new Human[capacity];
        copyResidents(other.residents, size);
    }

    ~Apartment() {
        delete[] residents;
    }

    void addResident(const Human& human) {
        if (size >= capacity) {
            capacity *= 2;
            Human* newResidents = new Human[capacity];
            copyResidents(residents, size);
            delete[] residents;
            residents = newResidents;
        }
        residents[size++] = human;
    }

    void printResidents() const {
        cout << "Residents in the apartment:" << endl;
        for (size_t i = 0; i < size; i++) {
            residents[i].printName();
        }
    }
};

class Building {
private:
    Apartment* apartments;
    size_t size;
    size_t capacity;

    void copyApartments(const Apartment* src, size_t count) {
        for (size_t i = 0; i < count; i++) {
            apartments[i] = src[i];
        }
    }

public:
    Building() : size(0), capacity(5) {
        apartments = new Apartment[capacity];
    }

    Building(const Building& other) : size(other.size), capacity(other.capacity) {
        apartments = new Apartment[capacity];
        copyApartments(other.apartments, size);
    }

    ~Building() {
        delete[] apartments;
    }

    void addApartment(const Apartment& apartment) {
        if (size >= capacity) {
            capacity *= 2;
            Apartment* newApartments = new Apartment[capacity];
            copyApartments(apartments, size);
            delete[] apartments;
            apartments = newApartments;
        }
        apartments[size++] = apartment;
    }

    void printApartments() const {
        cout << "Apartments in the building:" << endl;
        for (size_t i = 0; i < size; i++) {
            apartments[i].printResidents();
        }
    }
};

int main() {
    Building building;

    Apartment apartment1;
    apartment1.addResident(Human("John Doe"));
    apartment1.addResident(Human("Jane Doe"));

    Apartment apartment2;
    apartment2.addResident(Human("Alex Smith"));
    apartment2.addResident(Human("Michael Johnson"));

    building.addApartment(apartment1);
    building.addApartment(apartment2);

    building.printApartments();

    return 0;
}