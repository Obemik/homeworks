#include "doctor.h"

Doctor::Doctor(const char* name, const char* specialization, const char* doctorID) {
    _name = new char[strlen(name) + 1];
    strcpy_s(_name, strlen(name) + 1, name);
    _specialization = new char[strlen(specialization) + 1];
    strcpy_s(_specialization, strlen(specialization) + 1, specialization);
    _doctorID = new char[strlen(doctorID) + 1];
    strcpy_s(_doctorID, strlen(doctorID) + 1, doctorID);
}

Doctor::~Doctor() {
    delete[] _name;
    delete[] _specialization;
    delete[] _doctorID;
}

const char* Doctor::getDoctorID() const {
    return _doctorID; // Додано
}

void Doctor::showInfo() const {
    std::cout << "Name: " << _name << ", Specialization: " << _specialization << ", Doctor ID: " << _doctorID << std::endl; // Додано
}