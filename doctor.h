#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <cstring>

class Doctor {
    char* _name;
    char* _specialization;
    char* _doctorID;

public:
    Doctor(const char* name, const char* specialization, const char* doctorID);
    ~Doctor();
    const char* getDoctorID() const; // Додано
    void showInfo() const; // Додано
};

#endif // DOCTOR_H