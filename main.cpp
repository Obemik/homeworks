#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Reservoir {
private:
    string name;
    double width;
    double length;
    double maxDepth;
    string type;

public:
    Reservoir() : name("Unknown"), width(0.0), length(0.0), maxDepth(0.0), type("Unknown") {
    }

    explicit Reservoir(string reservoirName, double reservoirWidth, double reservoirLength, double reservoirMaxDepth, string reservoirType)
        : name(reservoirName), width(reservoirWidth), length(reservoirLength), maxDepth(reservoirMaxDepth), type(reservoirType) {
    }

    Reservoir(const Reservoir& other)
        : name(other.name), width(other.width), length(other.length), maxDepth(other.maxDepth), type(other.type) {
    }

    ~Reservoir() {
    }

    double calculateVolume() const {
        return width * length * maxDepth;
    }

    double calculateSurfaceArea() const {
        return width * length;
    }

    bool isSameType(const Reservoir& other) const {
        return this->type == other.type;
    }

    bool isLargerSurfaceAreaThan(const Reservoir& other) const {
        if (!isSameType(other)) {
            cout << "Reservoirs are of different types!" << endl;
            return false;
        }
        return this->calculateSurfaceArea() > other.calculateSurfaceArea();
    }

    Reservoir& operator=(const Reservoir& other) {
        if (this != &other) {
            name = other.name;
            width = other.width;
            length = other.length;
            maxDepth = other.maxDepth;
            type = other.type;
        }
        return *this;
    }

    string getName() const { return name; }
    double getWidth() const { return width; }
    double getLength() const { return length; }
    double getMaxDepth() const { return maxDepth; }
    string getType() const { return type; }

    void setName(const string& newName) { name = newName; }
    void setWidth(double newWidth) { width = newWidth; }
    void setLength(double newLength) { length = newLength; }
    void setMaxDepth(double newMaxDepth) { maxDepth = newMaxDepth; }
    void setType(const string& newType) { type = newType; }

    void printInfo() const {
        cout << "Reservoir: " << name << "\nType: " << type << "\nDimensions: " << width << " x " << length << " x " << maxDepth << endl;
    }
};

class ReservoirManager {
private:
    vector<Reservoir> reservoirs;

public:
    void addReservoir(const Reservoir& reservoir) {
        reservoirs.push_back(reservoir);
    }

    void removeReservoir(size_t index) {
        if (index < reservoirs.size()) {
            reservoirs.erase(reservoirs.begin() + index);
        }
    }

    void printAllReservoirs() const {
        for (const auto& reservoir : reservoirs) {
            reservoir.printInfo();
            cout << endl;
        }
    }

    void writeToTextFile(const string& fileName) const {
        ofstream file(fileName);
        if (file.is_open()) {
            for (const auto& reservoir : reservoirs) {
                file << reservoir.getName() << " " << reservoir.getType() << " " << reservoir.getWidth() << " "
                    << reservoir.getLength() << " " << reservoir.getMaxDepth() << endl;
            }
            file.close();
        }
        else {
            cout << "Error: Unable to open file for writing!" << endl;
        }
    }

    void writeToBinaryFile(const string& fileName) const {
        ofstream file(fileName, ios::binary);
        if (file.is_open()) {
            for (const auto& reservoir : reservoirs) {
                file.write((char*)&reservoir, sizeof(Reservoir));
            }
            file.close();
        }
        else {
            cout << "Error: Unable to open binary file for writing!" << endl;
        }
    }

    void readFromTextFile(const string& fileName) {
        ifstream file(fileName);
        if (file.is_open()) {
            reservoirs.clear();
            string name, type;
            double width, length, maxDepth;
            while (file >> name >> type >> width >> length >> maxDepth) {
                reservoirs.push_back(Reservoir(name, width, length, maxDepth, type));
            }
            file.close();
        }
        else {
            cout << "Error: Unable to open file for reading!" << endl;
        }
    }

    void readFromBinaryFile(const string& fileName) {
        ifstream file(fileName, ios::binary);
        if (file.is_open()) {
            reservoirs.clear();
            Reservoir tempReservoir;
            while (file.read((char*)&tempReservoir, sizeof(Reservoir))) {
                reservoirs.push_back(tempReservoir);
            }
            file.close();
        }
        else {
            cout << "Error: Unable to open binary file for reading!" << endl;
        }
    }
};

int main() {
    Reservoir res1("Lake Victoria", 50.0, 80.0, 25.0, "Lake");
    Reservoir res2("Dead Sea", 60.0, 100.0, 35.0, "Sea");

    cout << "Surface area of " << res1.getName() << ": " << res1.calculateSurfaceArea() << " square meters" << endl;
    cout << "Volume of " << res1.getName() << ": " << res1.calculateVolume() << " cubic meters" << endl;

    cout << "Surface area of " << res2.getName() << ": " << res2.calculateSurfaceArea() << " square meters" << endl;
    cout << "Volume of " << res2.getName() << ": " << res2.calculateVolume() << " cubic meters" << endl;

    return 0;
}