#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

enum Gender { Male, Female };

class Patient {
    std::string name;
    int age;
    Gender gender;
    std::string patientID;
    std::string address;

public:
    Patient(const std::string& name, int age, Gender gender, const std::string& patientID, const std::string& address);
    std::string getPatientID() const; // Додано
    void displayInfo() const; // Додано
};

#endif // PATIENT_H
