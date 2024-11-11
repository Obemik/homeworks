#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileProcessResult abstract
{
public:
    virtual void get_message() = 0;
};

template<typename T>
class FileInterface abstract
{
public:
    virtual FileProcessResult* open(ios_base::openmode mode) = 0;
    virtual FileProcessResult* close() = 0;
    virtual FileProcessResult* write(T data, ios_base::openmode mode) = 0;
    virtual FileProcessResult* read(T& data, ios_base::openmode mode) = 0;
    virtual FileProcessResult* read_by_index(T& data, ios_base::openmode mode, int itemIndex = 0) = 0;
};

class FileOpenSuccess : public FileProcessResult
{
public:
    FileOpenSuccess() = default;
    void get_message() override
    {
        cout << "File opened successfully" << endl;
    }
};

class FileOpenError : public FileProcessResult
{
public:
    FileOpenError() = default;
    void get_message() override
    {
        cout << "Error opening file" << endl;
    }
};

class FileCloseSuccess : public FileProcessResult
{
public:
    FileCloseSuccess() = default;
    void get_message() override
    {
        cout << "File closed successfully" << endl;
    }
};

class FileWriteSuccess : public FileProcessResult
{
public:
    FileWriteSuccess() = default;
    void get_message() override
    {
        cout << "Data written successfully" << endl;
    }
};

class FileWriteError : public FileProcessResult
{
    exception e;
public:
    FileWriteError() = default;
    FileWriteError(exception e)
    {
        this->e = e;
    }
    void get_message() override
    {
        cout << "Error writing data" << endl;
    }
};

class FileReadSuccess : public FileProcessResult
{
public:
    FileReadSuccess() = default;
    void get_message() override
    {
        cout << "Data read successfully" << endl;
    }
};

class FileReadError : public FileProcessResult
{
    exception e;
public:
    FileReadError() = default;
    FileReadError(exception e)
    {
        this->e = e;
    }
    void get_message() override
    {
        cout << "Error writing data" << endl;
    }
};

template<typename T>
class FileService : public FileInterface<T>
{
    string filename;
    fstream file;
public:
    FileService(string filename)
    {
        this->filename = filename;
    }
    FileProcessResult* open(ios_base::openmode mode) override
    {
        FileProcessResult* result = nullptr;
        file.open(filename, mode);
        if (file.is_open())
        {
            result = new FileOpenSuccess();
        }
        else
        {
            result = new FileOpenError();
        }
        return result;
    }
    FileProcessResult* close() override
    {
        file.close();
        return new FileCloseSuccess();
    }
    FileProcessResult* write(T data, ios_base::openmode mode) override
    {
        try
        {
            FileProcessResult* result = this->open(mode);
            result->get_message();
            if (typeid(*result) == typeid(FileOpenSuccess))
            {
                if (mode == ios::app || mode == ios::out || mode == (ios::out | ios::binary) || mode == (ios::app | ios::binary))
                {
                    file.write((char*)&data, sizeof(T));
                }
                else
                {
                    return new FileWriteError();
                }
                result = this->close();
                result->get_message();
                return new FileWriteSuccess();
            }
            else if (typeid(*result) == typeid(FileOpenError))
            {
                return new FileWriteError();
            }
        }
        catch (exception e)
        {
            return new FileWriteError(e);
        }
    }

    FileProcessResult* read(T& data, ios_base::openmode mode) override
    {
        try
        {
            FileProcessResult* result = this->open(mode);
            result->get_message();
            if (typeid(*result) == typeid(FileOpenSuccess))
            {
                if (mode == ios::in || mode == (ios::in | ios::binary))
                {
                    file.read((char*)&data, sizeof(T));
                }
                else
                {
                    return new FileWriteError();
                }
                result = this->close();
                result->get_message();
                return new FileReadSuccess();
            }
            else if (typeid(*result) == typeid(FileOpenError))
            {
                return new FileReadError();
            }
        }
        catch (exception e)
        {
            return new FileReadError(e);
        }
    }

    FileProcessResult* read_by_index(T& data, ios_base::openmode mode, int itemIndex = 0) override
    {
        try
        {
            FileProcessResult* result = this->open(mode);
            result->get_message();
            if (typeid(*result) == typeid(FileOpenSuccess))
            {
                if (mode == ios::in || mode == (ios::in | ios::binary))
                {
                    file.seekg(itemIndex * sizeof(T), ios::beg);
                    file.read((char*)&data, sizeof(T));
                }
                else
                {
                    return new FileWriteError();
                }
                result = this->close();
                result->get_message();
                return new FileReadSuccess();
            }
            else if (typeid(*result) == typeid(FileOpenError))
            {
                return new FileReadError();
            }
        }
        catch (exception e)
        {
            return new FileReadError(e);
        }
    }

};


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