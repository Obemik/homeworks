#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Human {
private:
    string fullName;

public:
    Human() : fullName("Unnamed") {}

    Human(const string& name) : fullName(name) {}

    void printName() const {
        cout << "Name: " << fullName << endl;
    }

    friend ostream& operator<<(ostream& os, const Human& human) {
        os << human.fullName;
        return os;
    }

    friend istream& operator>>(istream& is, Human& human) {
        is >> ws;
        getline(is, human.fullName);
        return is;
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
        for (size_t i = 0; i < size; i++) {
            residents[i].printName();
        }
    }

    friend ostream& operator<<(ostream& os, const Apartment& apartment) {
        os << apartment.size << endl;
        for (size_t i = 0; i < apartment.size; i++) {
            os << apartment.residents[i] << endl;
        }
        return os;
    }

    friend istream& operator>>(istream& is, Apartment& apartment) {
        is >> apartment.size;
        apartment.residents = new Human[apartment.size];
        for (size_t i = 0; i < apartment.size; i++) {
            is >> apartment.residents[i];
        }
        return is;
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
        for (size_t i = 0; i < size; i++) {
            apartments[i].printResidents();
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            file << size << endl;
            for (size_t i = 0; i < size; i++) {
                file << apartments[i];
            }
            file.close();
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            file >> size;
            apartments = new Apartment[size];
            for (size_t i = 0; i < size; i++) {
                file >> apartments[i];
            }
            file.close();
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

    building.saveToFile("building.txt");
    cout << "Дані збережено у файл." << endl;

    Building loadedBuilding;
    loadedBuilding.loadFromFile("building.txt");
    cout << "Завантажені дані з файлу:" << endl;
    loadedBuilding.printApartments();

    return 0;
}