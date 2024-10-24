#include "patient.h"

Patient::Patient(const std::string& name, int age, Gender gender, const std::string& patientID, const std::string& address)
    : name(name), age(age), gender(gender), patientID(patientID), address(address) {}

std::string Patient::getPatientID() const {
    return patientID; 
}

void Patient::displayInfo() const {
    std::cout << "Name: " << name << ", Age: " << age << ", Gender: " << (gender == Male ? "Male" : "Female") << ", Patient ID: " << patientID << ", Address: " << address << std::endl;
}
